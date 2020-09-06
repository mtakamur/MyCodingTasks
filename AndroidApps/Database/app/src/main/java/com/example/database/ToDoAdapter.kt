package com.example.database

import android.content.Context
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.recyclerview.widget.RecyclerView
import kotlinx.android.synthetic.main.to_do_list.view.*

class ToDoAdapter(private val toDoList: List<ToDo>): RecyclerView.Adapter<ToDoAdapter.ViewHolder>(){
    class ViewHolder(view: View): RecyclerView.ViewHolder(view){
        val content = view.text_todo
        val date = view.text_date
    }

    override fun getItemCount(): Int {
        return toDoList.size
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
        val layoutInflater = LayoutInflater.from(parent.context)
        return ViewHolder(layoutInflater.inflate(R.layout.to_do_list, parent, false))
    }

    override fun onBindViewHolder(holder: ViewHolder, position: Int) {
    }
}