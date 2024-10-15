#include <stdio.h>

int partition (int *v , int l , int r ) {
 int pivot = v [ r ];
 int i = l -1 , j = r ;

 while (i < j ) {

 while ( v [++ i] < pivot ) ;
 while ( v [ - - j] > pivot && j > l );

 if(i < j ) exch ( v [ i ] , v [ j ]);
 }
 exch ( v [ i ] , v [ r ]) ;

 return i ;
 }

void quick_sort (int *v , int l , int r )
 {
 if(r <= l ) return ;

 int p = partition (v , l , r ) ;

 quick_sort (v , l , p -1) ;
 quick_sort (v , p +1 , r );
 }