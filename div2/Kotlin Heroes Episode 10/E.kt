fun main() {
    var t = readLine()!!.toInt()
    repeat(t) {
        var (n, k) = readLine()!!.split(" ").map { it.toInt() }
        if (k - 1 >= log2(n.toDouble())) {
            println(-1)
            return@repeat
        }
        val ans = IntArray(n + 1)
        var now = 1
        var cnt = 0
        var i = 1
        while (i <= n && cnt < k) {
            var j = i
            while (j <= n) {
                ans[j] = now++
                j += i * 2
            }
            i *= 2
            cnt++
        }
        while (i <= n) {
            if (ans[i] == 0) {
                ans[i] = now++
            }
            i++
        }
        for (i in 2..n) {
            print("${ans[i]} ")
        }
        println()
    }
}

fun log2(x: Double): Int {
    return (Math.log(x) / Math.log(2.0)).toInt()
}
