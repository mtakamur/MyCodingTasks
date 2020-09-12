package com.example.discount

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Toast
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
    }

    fun onCalculateClick(view: View) {
        val amount = edit_amount.text.toString().toIntOrNull()
        val discountRatio = edit_discount_ratio.text.toString().toIntOrNull()
        if (amount == null || discountRatio == null
            || amount <= 0
            || discountRatio <= 0 || 100 < discountRatio
        ) {
            Toast.makeText(this, getString(R.string.invalid_input), Toast.LENGTH_SHORT).show()
            return
        }
        Toast.makeText(
            this,
            getString(R.string.calculation_result, calculateDiscountedAmount(amount,discountRatio)),
            Toast.LENGTH_SHORT
        ).show()
    }
}

