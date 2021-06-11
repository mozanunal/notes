```go
package main

import (
    "fmt"
    "time"
    "math/rand"
    "math"
    "runtime"
)

// Notes
// rand.Seed to add random seed
// exported varibles should start with capital letter like math.Pi
// init values 0, false, ""
// defer executed after funtion done
// if there are multiple defers they are stacked and executed in stack order
// slices does not store data changing elements of slices original array
//


type Vertex struct {
    X int
    Y int
}

func (v *Vertex) Scale(f float64) {
    v.X = v.X * f
    v.Y = v.Y * f
}
// run with v.Scale(5)

func ScaleFunc(v *Vertex, f float64) {
    v.X = v.X * f
    v.Y = v.Y * f
}
// run with ScaleFunc(v)


func add_subtract(x int, y int) (int,int) {
    return x + y, x - y
}



func add_subtract(x int, y int) (sum int, sub int) {
    sum = x + y
    sub = x - y
    return
}

func main() {

    // print
    fmt.Println("Welcome to the playground!")
    fmt.Println("The time is", time.Now())
    fmt.Printf("Test Printf %g \n", math.Sqrt(7))

    // varibles
    var a,b,c int
    var un64 uint64
    var comp128 complex128
    var d, e, f = true, 22, "hey"
    g, h, j := true, 22, "hey"
    int a = 12
    a := 12
    var f float64 = float64(a)
    const Pi = 3.14


    // loops and conditions

    for i:=0; i < 10 i++ {
        fmt.Println(i)
    }

    for i < 1000 {
    
    }

    for {
    }

    if a > 8 {
    
    }

    switch os := runtime.GOOS; os{
    case "darwin":
        fmt.Println("OSX")
    case "linux":
        fmt.Println("Linux")
    default:
        //something
    }

    // defer statements are executed after the fucntion returns
    defer fmt.Println("world")

    // pointers
    p := &a
    *p = 21

    // struct
    v := Vertex{ 12, 5}
    v := Vertex{X:1} // X=1 Y=0
    v := Vertex{} // X=0 Y=0
    v.X = 4

    pv := &v

    // arrays
    var a[10] int

    // slices
    var s[]int = a[1:4]
    a[1:]
    a[:3]

    s := make([]int, 5)
    s = append(s, 20)


    for i, v: range s {
        fmt.Printf("%dth element is %d")
    }

    // maps
    m = make(map[string]Vertex)
    m["home"] = Vertex{40.2312, 30.232}
    fmt.Println(m["home"]
    delete(m, "home")
    elem, ok = m["home"]

    //functions
    hypot := func(x, y float64) float64 {
        return math.Sqrt(x*x + y*y)
    }

    var m = map[string]Vertex{
    "Bell Labs": {40.68433, -74.39967},
    "Google":    {37.42202, -122.08408},
    }

    // interfaces
    var i interface{}
    i = 42
    i = "hello"
    f, ok := i.(float64)
    fmt.Println(f, ok)

    switch t := i.(type) {
    case int:
    fmt.Printf("Twice %v is %v\n", v, v*2)
    case string:
    fmt.Printf("%q is %v bytes long\n", v, len(v))
    default:
    fmt.Printf("I don't know about type %T!\n", v)
    }

    //
    i, err := strconv.Atoi("42")
    if err != nil {
        fmt.Printf("couldn't convert number: %v\n", err)
        return
    }
    fmt.Println("Converted integer:", i)

    // readers
    r := strings.NewReader("Hello, Reader!")
    b := make([]byte, 8)
    for {
    n, err := r.Read(b)
    fmt.Printf("n = %v err = %v b = %v\n", n, err, b)
    fmt.Printf("b[:n] = %q\n", b[:n])
    if err == io.EOF {
        break
        }
    }

    //goroutines
    // go funcname(arguments)

    // channels
    ch := make(chan int)
    ch <- v    // Send v to channel ch.
    v := <-ch  // Receive from ch, and assign v
    ch := make(chan int, 100) // buffered channel

    // select
    tick := time.Tick(100 * time.Millisecond)
    boom := time.After(500 * time.Millisecond)
    for {
        select {
            case <-tick:
                fmt.Println("tick.")
            case <-boom:
                fmt.Println("BOOM!")
                return
            default:
                fmt.Println("    .")
                time.Sleep(50 * time.Millisecond)
            }
    }

    // sync.Mutex
    // SafeCounter is safe to use concurrently.
    type SafeCounter struct {
        v   map[string]int
	mux sync.Mutex
    }

    // Inc increments the counter for the given key.
    func (c *SafeCounter) Inc(key string) {
	c.mux.Lock()
	// Lock so only one goroutine at a time can access the map c.v.
	c.v[key]++
	c.mux.Unlock()
    }

    // Value returns the current value of the counter for the given key.
    func (c *SafeCounter) Value(key string) int {
	c.mux.Lock()
	// Lock so only one goroutine at a time can access the map c.v.
	defer c.mux.Unlock()
	return c.v[key]
    }

    



}


```
