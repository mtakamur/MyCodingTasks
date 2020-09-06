package com.example.database

import android.content.ContentValues
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
    }

    fun onLoadClick(view: View) {
        val db = Database(this).readableDatabase

        val cursor = db.query(
            "User",
            arrayOf("_id", "name", "age"),
            "age > ?",
            arrayOf("20"),
            null,
            null,
            "age DESC",
            null
        )
        cursor.use { c ->
            while(c.moveToNext()){
                val id = c.getLong(c.getColumnIndex("_id"))
                val name = c.getString(c.getColumnIndex("name"))
                val age = c.getInt(c.getColumnIndex("age"))
                text_name.text = name
                text_age.text = age.toString()
            }
        }
        db.close()
    }

    fun onAddClick(view: View) {
        val name = edit_name.text.toString()
        val age = edit_age.text.toString()
        if (name.isNotBlank() && age.isNotBlank()) {
            val db = Database(this).writableDatabase
            val record = ContentValues().apply {
                put("name", name)
                put("age", age)
            }
            db.insert("User", null, record)
            db.close()
        }
    }
}