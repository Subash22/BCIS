#include <stdio.h>
#include <conio.h>
main()
{
	int arr[100],key,i,n;
	// Get the size of array
	printf("Enter the number of element in array \n");
	scanf("%d", &n);

	// Insert elements in array
	printf("Enter %d numbers \n", n);
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	// Search element from array
	printf("\nENTER A NUMBER TO SEARCH: ");
	scanf("%d", &key);
	if(key==arr[i]){
		printf("\nTHE NUMBER %d EXISTS IN THE ARRAY",key);
	} else{
		printf("\nTHE NUMBER %d DOES NOT EXIST IN THE ARRAY",key);
	}
	getch();
}

// Command
// .\exe file name