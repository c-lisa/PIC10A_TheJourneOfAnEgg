/****************************************
Lisa Chiang 
304-255-524
Pic10A - hw5.cpp "The Journey of the Egg"
****************************************/

#include"ccc_win.h"
#include<time.h>
using namespace std;

void set_screen()
{
	//setting up the board and dimensions
	cwin.coord(0, 22, 26, 0);
	Point b1(1, 21), b2(25, 21), b3(1, 1), b4(25, 1);
	Line bo1(b1, b2), bo2(b2, b4), bo3(b3, b4), bo4(b1, b3);
	cwin << bo1 << bo2 << bo3 << bo4;
	Point b5(1, 19), b6(25, 19);
	Line bo5(b5, b6);
	cwin << bo5;
	Point b7(6, 21), b8(6, 1), b9(15, 21), b10(15, 1);
	Line bo6(b7, b8), bo7(b9, b10);
	cwin << bo6 << bo7;
	Point b11(6, 13), b12(15, 13), b13(6, 7), b14(15, 7);
	Line bo8(b11, b12), bo9(b13, b14);
	cwin << bo8 << bo9;
	Point b15(15, 10); Point b16(25, 10);
	Line bo10(b15, b16);
	cwin << bo10;

	//naming categories
	Message click1a(Point(1, 21), "1. Click somewhere");
	Message click1b(Point(1, 20.5), "in this column to");
	Message click1c(Point(1, 20), "get your egg.");
	Message click2a(Point(6, 20.5), "2. Pick and click one of the factors");
	Message click2b(Point(6, 20), "of growth in this column.");
	Message click3a(Point(15, 20.5), "3. Pick and click a place for your egg's final");
	Message click3b(Point(15, 20), "destination in this column.");
	cwin << click1a << click1b << click1c << click2a << click2b << click3a << click3b;

	//drawing nourishment #1 - sun
	Point S1(10.5, 16);
	Circle S(S1, 1.5);
	cwin << S;
	Point s1(10.5, 19), s2(10.5, 18), s3(12, 17), s4(13, 18), s5(12.5, 16), s6(13.5, 16),
		s7(12, 15), s8(13, 14), s9(10.5, 14), s10(10.5, 13), s11(9, 15), s12(8, 14),
		s13(8.5, 16), s14(7.5, 16), s15(9, 17), s16(8, 18);
	Line su1(s1, s2), su2(s3, s4), su3(s5, s6), su4(s7, s8), su5(s9, s10), su6(s11, s12),
		su7(s13, s14), su8(s15, s16);
	cwin << su1 << su2 << su3 << su4 << su5 << su6 << su7 << su8;

	//drawing nourishment #2 - the food
	Point f1(8, 12), f2(13, 12), f3(8, 8), f4(13, 8), f5(9, 12.5), f6(14, 12.5),
		f7(14, 9);
	Line fo1(f1, f2), fo2(f2, f4), fo3(f3, f4), fo4(f3, f1), fo5(f5, f1), fo6(f5, f6),
		fo7(f6, f2), fo8(f6, f7), fo9(f7, f4);
	cwin << fo1 << fo2 << fo3 << fo4 << fo5 << fo6 << fo7 << fo8 << fo9;
	Message food(Point(9.5, 10.5), "F O O D");
	cwin << food;

	//drawing nourishment #3 - the water
	Point w1(9, 6), w2(12, 6), w3(12, 3), w4(11.5, 2), w5(9.5, 2), w6(9, 3),
		w7(9, 4.2), w8(9.8, 4.05), w9(11, 4.05), w10(12, 4.1);
	Line wa1(w1, w2), wa2(w2, w3), wa3(w3, w4), wa4(w4, w5), wa5(w5, w6), wa6(w6, w1),
		wa7(w7, w8), wa8(w8, w9), wa9(w9, w10);
	cwin << wa1 << wa2 << wa3 << wa4 << wa5 << wa6 << wa7 << wa8 << wa9;
	Message H20(Point(9.8, 3), "H 2 0");
	cwin << H20;

	//drawing result#1 - the home
	Point h1(16, 17), h2(24, 17), h3(24, 10.5), h4(16, 10.5), h5(20, 18);
	Line H1(h1, h2), H2(h2, h3), H3(h3, h4), H4(h4, h1), H5(h1, h5), H6(h5, h2);
	cwin << H1 << H2 << H3 << H4 << H5 << H6;
	Message Home(Point(16, 10.5), "H O M E");
	cwin << Home;

	//drawing result #2 - the pan 
	Point Pan(19, 5);
	Circle PanI(Pan, 3);
	Circle PanO(Pan, 2.8);
	cwin << PanI << PanO;
	Point Pan1(20.26, 7.75), Pan2(22.08, 9.67), Pan3(22.92, 9.245), Pan4(20.856, 7.35);
	Line Pann1(Pan1, Pan2), Pann2(Pan2, Pan3), Pann3(Pan3, Pan4);
	cwin << Pann1 << Pann2 << Pann3;
	Message Pan_(Point(16.75, 5), "F R Y I N G  P A N");
	cwin << Pan_;

	//drawing the egg - initial condition
	Point egg(3.5, 10);
	Circle E(egg, 1.5);
	cwin << E;

}

/**************************
drawing the arrow
(the main animated object)
P = center
f# = feather part of arrow
t# = tip of arrow
r = scale/index
**************************/
void draw_arrow(Point P, double r)
{
	double x, y; //center of arrow

	x = P.get_x();
	y = P.get_y();

	//multiplying distances from center (x,y) to enlarge arrow size
	Point f1(x - 2 * r, y), f2(x - 2.5*r, y + 0.5*r), f3(x - 1.5*r, y + 0.5*r),
		f4(x - 2.5*r, y - 0.5*r), f5(x - 1.5*r, y - 0.5*r), f6(x - 1 * r, y);
	Point t1(x + 2.5*r, y), t2((x + 2 * r), (y + 0.5*r)), t3((x + 2 * r), (y - 0.5*r));
	Line fe1(f6, f3), fe2(f3, f2), fe3(f2, f1), fe4(f1, f4), fe5(f4, f5), fe6(f5, f6);
	Line shaft(f6, t1);
	Line ti1(t1, t2), ti2(t3, t1);
	cwin << fe1 << fe2 << fe3 << fe4 << fe5 << fe6 << shaft << ti1 << ti2;

}

//draws the effect when arrow reaches sun
void draw_smileonsun()
{
	Point sm1(9.8, 16), sm2(11, 16), sm3(10, 15.4), sm4(10.5, 14.8), sm5(11, 15.4);
	Line smile1(sm3, sm4), smile2(sm4, sm5);
	cwin << sm1 << sm2 << smile1 << smile2;
}

//draws the effect when arrow reaches food
void draw_yum()
{
	Message yum_food(Point(9, 7.8), "YUMMMY :-]");
	Circle packaging(Point(10.45, 9.91), 1.7);
	cwin << yum_food << packaging;
}

//draws the effect when arrow reaches water
void draw_drinkwater()
{
	Message drink_water(Point(7, 1.7), "Hydration started yesterday");
	cwin << drink_water;
}

//draws the effect when arrow reaches home
void draw_chick()
{
	Point eyes1(19, 14.5), eyes2(21, 14.5);
	cwin << eyes1 << eyes2;
	Point bea1(19.5, 14), bea2(20.5, 14), bea3(20, 13.75);
	Line beak1(bea1, bea2), beak2(bea2, bea3), beak3(bea3, bea1);
	cwin << beak1 << beak2 << beak3;
	Circle chick(Point(20, 14), 2);
	cwin << chick;
	Point wi1(18, 14), wi2(17, 14), wi3(17.5, 13.3), wi4(22, 14), wi5(23, 14), wi6(22.5, 13.3);
	Line wing1(wi1, wi2), wing2(wi2, wi3), wing3(wi3, wi1), wing4(wi4, wi5), wing5(wi5, wi6), wing6(wi6, wi4);
	cwin << wing1 << wing2 << wing3 << wing4 << wing5 << wing6;
	Point fe1(18.8, 12.1), fe2(18.8, 11.6), fe3(18.5, 11.6);
	Point fe4(21.2, 12.1), fe5(21.2, 11.6), fe6(21.5, 11.6);
	Line feet1(fe1, fe2), feet2(fe2, fe3), feet3(fe4, fe5), feet4(fe5, fe6);
	cwin << feet1 << feet2 << feet3 << feet4;
}

//draws the effect when arrow reaches frying pan
void draw_cookingpan()
{
	//cracked egg
	Circle cracked_egg(Point(23, 3), 1);
	cwin << cracked_egg;
	Point crack3(23, 3), crack2(22.8, 2.8), crack1(22, 3), crack4(23.3, 2.5), crack5(24, 3.17);
	Line cracked1(crack3, crack2), cracked2(crack2, crack1), cracked3(crack3, crack4), cracked4(crack4, crack5);
	cwin << cracked1 << cracked2 << cracked3 << cracked4;

	//cooked egg
	Circle cooked_white(Point(19, 6.5), 1);
	Circle cooked_yolk(Point(19, 6.5), 0.5);
	cwin << cooked_white << cooked_yolk;
}

/********************************************
pausing the animation so you can see movement
x = number of milliseconds
function was given by professor
********************************************/

void pause(int x)
{
	clock_t goal = x + clock();
	while (goal > clock());
}

/******************************
actually running the animation
******************************/
void animate(int pause_interval, int num_steps, Point start, Point stop, int x)
{
	//starting coordinates
	double x1 = start.get_x();
	double y1 = start.get_y();

	//stopping coordinates
	double x2 = stop.get_x();
	double y2 = stop.get_y();

	//changes in coordinates for every frame - THE SLOPE
	double dx = (x2 - x1) / num_steps;
	double dy = (y2 - y1) / num_steps;

	//running a for loop with num_steps
	if (x == 0) //runs the loop that moves arrow from first to second column, arrow enlargens
	{
		for (int i = 0; i < num_steps; ++i)
		{
			//coordinates for this current frame
			double x = i*dx + x1; //new x = the counter*the slope + the original x
			double y = i*dy + y1;

			//new location point
			Point P(x, y); //new arrow location with above coordinates

			//clear screen quickly
			cwin.clear(); //clear for next arrow

			//reset screen
			set_screen(); //recreate diagram/board

			//draw shape at that location with the scale
			draw_arrow(P, 0.255 + i*0.0055); //0.255 + (the size of the arrow initially + counter*scaling)

			//draw smiley face or message
			if (x > 6 && x < 15)
			{
				if (y > 13 && y < 19)
				{
					//smiley face on sun
					draw_smileonsun();
				}
				else if (y < 13 && y > 7)
				{
					//yummy food
					draw_yum();
				}
				else if (y < 7 && y >1)
				{
					//drink water
					draw_drinkwater();
				}
			}

			//pause for pause_interval
			pause(pause_interval);

		}
	}
	if (x == 1) //runs the loop that moves the arrow from second to third column, arrow shrinks
	{
		for (int i = 0; i < num_steps; ++i)
		{
			//coordinates for this frame
			double x = i*dx + x1;
			double y = i*dy + y1;

			//new location point
			Point P(x, y);

			//clear screen quickly
			cwin.clear();

			//reset screen
			set_screen();

			//draw shape at that location with the scale
			draw_arrow(P, (0.255 + num_steps*0.0055) - i*0.0055); //shrinks this time by taking maximum scaling and decreasing from there

			if (x > 15 && x < 25)
			{
				if (y < 19 && y > 10)
				{
					draw_chick();
				}
				else if (y < 10 && y > 1)
				{
					draw_cookingpan();
				}
			}

			//pause for pause_interval
			pause(pause_interval);
		}
	}
}

int ccc_win_main()
{
	set_screen();

	//getting three clicks from three columns according to directions
	Point P = cwin.get_mouse("Follow instructions in #1.");
	Point P2 = cwin.get_mouse("Follow instructions in #2.");
	Point P3 = cwin.get_mouse("Follow instructions in #3.");

	//setting first start and stop (first - second column)
	Point start = P;
	Point stop = P2;

	//call animation with supplied points
	animate(50, 150, start, stop, 0);

	//setting second start and stop (second-tihrd column)
	start = P2;
	stop = P3;

	//call animation with supplied points
	animate(50, 150, start, stop, 1);

	return 0;
}


