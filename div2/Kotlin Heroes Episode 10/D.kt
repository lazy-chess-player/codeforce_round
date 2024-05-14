fun solve() {
    var n = readLine()!!.toInt()
    var a = LongArray(n + 10)
    var sums = LongArray(n + 10)
    for (i in 1..n) {
        a[i] = readLine()!!.toLong()
        sums[i] = sums[i - 1] + a[i]
    }
    var ans = 0L
    var maxDel = 0L
    for (l in 0 until n + 1) {
        var r = l + 1
        while (r <= n + 1) {
            if (a[r] == 0L) {
                ans += (sums[r - 1] - sums[l]) * 2
                if ((r - l - 1) % 2 == 1) {
                    ans -= maxDel
                }
                maxDel = 0
                break
            } else if ((r - l) % 2 == 1) {
                maxDel = maxOf(maxDel, a[r])
            }
            r++
        }
    }
    println(ans)
}

fun main() {
    var t = 1
    repeat(t) { solve() }
}
