#include <xc.h> // include processor files - each processor file is guarded.

uint16_t const coss[91] = { // cos val by degree * hff
/*
>>> for i in range (1, 91):
...  print('{},'.format(round(math.cos(math.radians(i)) * 65536)))
...
 */    
65535,
65526,
65496,
65446,
65376,
65287,
65177,
65048,
64898,
64729,
64540,
64332,
64104,
63856,
63589,
63303,
62997,
62672,
62328,
61966,
61584,
61183,
60764,
60326,
59870,
59396,
58903,
58393,
57865,
57319,
56756,
56175,
55578,
54963,
54332,
53684,
53020,
52339,
51643,
50931,
50203,
49461,
48703,
47930,
47143,
46341,
45525,
44695,
43852,
42995,
42126,
41243,
40348,
39441,
38521,
37590,
36647,
35693,
34729,
33754,
32768,
31772,
30767,
29753,
28729,
27697,
26656,
25607,
24550,
23486,
22415,
21336,
20252,
19161,
18064,
16962,
15855,
14742,
13626,
12505,
11380,
10252,
9121,
7987,
6850,
5712,
4572,
3430,
2287,
1144,
0};

int16_t cos(int16_t pDegree4, bool* pRevers) //
/**
  @Summary
 return cos value * 65536 by degree * 4

  @Description

  @Preconditions
2
  @Param   
 p_degree - degree value * 2*/
{
    uint8_t degree_minor = pDegree4 & 3;
    uint16_t dg = pDegree4 >> 2;
    *pRevers = (pDegree4 > 360 && pDegree4 < 1080 * 4) ? true : false; // if 270 < degree > 90
    if (dg > 180) dg -= 180;  // move from third or fourth sector to first or second
    if (dg > 90) dg = 180 - dg; // move from second to first sectorgd
    
        uint16_t steep = degree_minor > 0 ? coss[dg - 1] - coss[dg] : 0;
        uint16_t val1 = coss[dg];
        uint8_t  val2 = (steep >> 2)* degree_minor;
        return val1 + val2;
}


 uint16_t sins[91] = 
 {0,
     1144,
2287,
3430,
4572,
5712,
6850,
7987,
9121,
10252,
11380,
12505,
13626,
14742,
15855,
16962,
18064,
19161,
20252,
21336,
22415,
23486,
24550,
25607,
26656,
27697,
28729,
29753,
30767,
31772,
32768,
33754,
34729,
35693,
36647,
37590,
38521,
39441,
40348,
41243,
42126,
42995,
43852,
44695,
45525,
46341,
47143,
47930,
48703,
49461,
50203,
50931,
51643,
52339,
53020,
53684,
54332,
54963,
55578,
56175,
56756,
57319,
57865,
58393,
58903,
59396,
59870,
60326,
60764,
61183,
61584,
61966,
62328,
62672,
62997,
63303,
63589,
63856,
64104,
64332,
64540,
64729,
64898,
65048,
65177,
65287,
65376,
65446,
65496,
65526, 
65535};
 
 uint16_t sin(int16_t pDegree4, bool* pRevers) //
/**
  @Summary
 return sin value * 65536 by degree * 4

  @Description

  @Preconditions

  @Param
 p_degree - degree value * 4*/
{
    uint8_t degree_minor = pDegree4 & 3;
    uint16_t dg = pDegree4 >> 2;
    *pRevers = dg > 180 ? true : false; 
    if (dg > 180) dg -= 180;  // move from third or fourth sector to first or second
    if (dg > 90) dg = 180 - dg; // move from second to first sector
    uint16_t steep = degree_minor > 0 ? sins[dg] - sins[dg -1] : 0; // get delta to next value in stream
    uint16_t val1  = sins[dg];
    uint8_t  val2 = (steep >> 2)* degree_minor;
    return val1 - val2; // correcting value to steep devided on minor part
}
 
 const int16_t START_ARROW_POSITION = 180 << 2; // degree * 4
 const uint8_t DegreePerKm7 = 120; // degree per km * 128
 
 int getArrowDegree4(uint32_t p_speed4) 
 
    { 
     uint32_t r1 = p_speed4 * DegreePerKm7;
     uint16_t r2 = r1 >> 7;
     return (r2 > START_ARROW_POSITION) ? (360 << 2) + START_ARROW_POSITION - r2 : START_ARROW_POSITION - r2;
    }