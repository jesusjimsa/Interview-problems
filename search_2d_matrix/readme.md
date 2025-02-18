# Description

Write an efficient algorithm that searches for a value `target` in an `m x n` integer matrix matrix. This matrix has the following properties:

* Integers in each row are sorted in ascending from left to right.
* Integers in each column are sorted in ascending from top to bottom.

## Example 1

<table border="1">
    <tr>
        <td>1</td>
        <td>4</td>
        <td>7</td>
        <td>11</td>
        <td>15</td>
    </tr>
    <tr>
        <td>2</td>
        <td style="background-color: lightgreen;">5</td>
        <td>8</td>
        <td>12</td>
        <td>19</td>
    </tr>
    <tr>
        <td>3</td>
        <td>6</td>
        <td>9</td>
        <td>16</td>
        <td>22</td>
    </tr>
    <tr>
        <td>10</td>
        <td>13</td>
        <td>14</td>
        <td>17</td>
        <td>24</td>
    </tr>
    <tr>
        <td>18</td>
        <td>21</td>
        <td>23</td>
        <td>26</td>
        <td>30</td>
    </tr>
</table>

```
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true
```

## Example 2

<table border="1">
    <tr>
        <td>1</td>
        <td>4</td>
        <td>7</td>
        <td>11</td>
        <td>15</td>
    </tr>
    <tr>
        <td>2</td>
        <td>5</td>
        <td>8</td>
        <td>12</td>
        <td>19</td>
    </tr>
    <tr>
        <td>3</td>
        <td>6</td>
        <td>9</td>
        <td>16</td>
        <td>22</td>
    </tr>
    <tr>
        <td>10</td>
        <td>13</td>
        <td>14</td>
        <td>17</td>
        <td>24</td>
    </tr>
    <tr>
        <td>18</td>
        <td>21</td>
        <td>23</td>
        <td>26</td>
        <td>30</td>
    </tr>
</table>

```
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false
```

## Constraints:

* `m == matrix.length`
* `n == matrix[i].length`
* `1 <= n, m <= 300`
* `-10^9 <= matrix[i][j] <= 10^9`
* All the integers in each row are sorted in ascending order.
* All the integers in each column are sorted in ascending order.
* `-10^9 <= target <= 10^9`

From [Leetcode](https://leetcode.com/problems/search-a-2d-matrix-ii).

Solved in C.
