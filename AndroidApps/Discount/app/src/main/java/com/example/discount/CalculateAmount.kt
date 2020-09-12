package com.example.discount

fun calculateDiscountedAmount(amount: Int, discountRatio: Int): Int {
    return (amount * (100 - discountRatio)) / 100
}
