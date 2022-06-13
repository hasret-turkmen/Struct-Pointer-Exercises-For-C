#include <stdio.h>
#include <math.h>
#define MAX_SHAPES 50
#define PI 3.141593
typedef  struct
{
    double x;
    double y;
    double z;
}point_t;



typedef  struct
{
    point_t center;
    double radius;
    double volume;
}sphere_t;


typedef  struct
{
    point_t bottom_left_furthest_corner;
    double side;
    double volume;
}cube_t;



typedef  struct
{
    point_t base_center;
    double base_radius;
    double height;
    double volume;
}cylinder_t;

typedef  union
{
    sphere_t sphere;
    cube_t cube;
    cylinder_t cylinder;
}shape_data_t;

typedef enum
{
    SPHERE,
    CUBE,
    CYLINDER
}*class_t;



typedef struct
{
    class_t c;
    shape_data_t shape;

} shape_t;



int scanShape(FILE *filep, shape_t *objp);
int loadShapes(shape_t shapes[]);
void printShape(const shape_t *objp);

int main()
{
   shape_t shapes[MAX_SHAPES];
    int numOfShapes = loadShapes(shapes);

    printf("\nShapes:\n");
    for (int i = 0; i < numOfShapes; i++)
        printShape(&shapes[i]);
    return 0;
}

int scanShape(FILE *filep, shape_t *objp){

    char shape[50];
    double d1,d2,d3,d4;

    int args = fscanf(filep,"%s",shape);

    if(args !=1 ){
        return 0;
    }

    args = fscanf(filep,"%lf %lf %lf %lf",&d1,&d2,&d3,&d4);

    if(args <0){
        return 0 ;
    }


    if(strcmp(shape,"cylinder")==0){
        double d5;
        fscanf(filep,"%lf",&d5);

        objp->c = CYLINDER;
        objp->shape.cylinder.base_center.x=d1;
        objp->shape.cylinder.base_center.y=d2;
        objp->shape.cylinder.base_center.z= d3;
        objp->shape.cylinder.base_radius = d4;
        objp->shape.cylinder.height = d5;
        objp->shape.cylinder.volume = PI*d4*d4*d5;
    }

    if(strcmp(shape,"sphere")==0){
        objp->c = SPHERE;
        objp->shape.sphere.center.x = d1;
         objp->shape.sphere.center.y = d2;
         objp->shape.sphere.center.z= d3;
         objp->shape.sphere.radius = d4;
        objp->shape.sphere.volume = PI*d4*d4*d4*4/3;
    }

    if(strcmp(shape,"cube")==0){
        objp->c=CUBE;
        objp->shape.cube.bottom_left_furthest_corner.x= d1;
        objp->shape.cube.bottom_left_furthest_corner.y= d2;
        objp->shape.cube.bottom_left_furthest_corner.z= d3;
        objp->shape.cube.side = d4;
        objp->shape.cube.volume = d4*d4*d4;
    }
    return 1;
}


int loadShapes(shape_t shapes[]){

    FILE *filep;
    printf("Enter the file name to read\n");
    char filename[100];
    scanf("%s",filename);

    printf("Opening %s\n",filename);
    filep = fopen(filename,"r");

    int args = 1;
    int i=0;
    while(args!=0){
        args = scanShape(filep,&shapes[i]);
        i++;
    }

    printf("Loading complete\nClosing %s\n",filename);
    fclose(filep);

    return i-1;
}

void printShape(const shape_t *objp){

    if(objp->c == SPHERE){
        double x, y, z,r,v;
        x = objp->shape.sphere.center.x;
        y = objp->shape.sphere.center.y;
        z = objp->shape.sphere.center.z;
        r = objp->shape.sphere.radius;
        v = objp->shape.sphere.volume;
        printf("Sphere: <%.2f %.2f %.2f> <%.2f> V<%.2f>\n",x,y,z,r,v);
    }

    if(objp->c == CUBE){
        double x, y, z,s,v;

        x = objp->shape.cube.bottom_left_furthest_corner.x;
        y = objp->shape.cube.bottom_left_furthest_corner.y;
        z = objp->shape.cube.bottom_left_furthest_corner.z;
        s = objp->shape.cube.side;
        v= objp->shape.cube.volume;
        printf("Cube: <%.2f %.2f %.2f> <%.2f> V<%.2f>\n",x,y,z,s,v);
    }

    if(objp->c == CYLINDER){
        double x,y,z,r,h,v;
        x = objp->shape.cylinder.base_center.x;
        y = objp->shape.cylinder.base_center.y;
        z = objp->shape.cylinder.base_center.z;
        r = objp->shape.cylinder.base_radius;
        h = objp->shape.cylinder.height;
        v = objp->shape.cylinder.volume;
        printf("Cylinder: <%.2f %.2f %.2f> <%.2f> <%.2f> V<%.2f>\n",x,y,z,r,h,v);
    }
}

