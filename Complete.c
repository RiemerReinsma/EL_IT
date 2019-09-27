#pragma config(Sensor, S1,     ultra,          sensorEV3_Ultrasonic)
#pragma config(Sensor, S4,     lys,            sensorEV3_Color)
#pragma config(Motor,  motorA,          venstre,       tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorB,          arm,           tmotorEV3_Medium, PIDControl, encoder)
#pragma config(Motor,  motorD,          hoejre,        tmotorEV3_Large, PIDControl, driveRight, encoder)


int sort=0;

void koerGraa()
{
	setLEDColor(ledGreen);
	setMotorSpeed(hoejre,30);                //drejer mod venstre
	setMotorSpeed(venstre,10);
}

void koerHvid()
{
	setMotorSpeed(hoejre,10);	               //drejer mod h�jre
	setMotorSpeed(venstre,30);
}

void koerGraa2()
{
	setMotorSpeed(hoejre,10);								 // drejer langsomt mod venstre
	setMotorSpeed(venstre,5);							   // bruges kun i udfordring 7
}

void koerHvid2()
{
	setMotorSpeed(hoejre,5);								 // drejer langsomt mod venstre
	setMotorSpeed(venstre,10);							 // bruges kun i udfordring 7
}
/*
void turn90 ()                             // Robotten drejer 90 grader til h�jre
{
setMotorSpeed(hoejre, -5);
setMotorSpeed(venstre, 5);
sleep(3325);
setMotorSpeed(hoejre, 0);
setMotorSpeed(venstre, 0);
}

void turn180 ()                            // Robotten drejer 180 grader venstre om
{

setMotorSpeed(hoejre, 5);
setMotorSpeed(venstre, -5);
sleep(6800);
setMotorSpeed(hoejre, 0);
setMotorSpeed(venstre, 0);
}
*/
void registrerSort() 											//registrerer sort, k�rer lidt frem s� den ikke registrerer igen.
{
	setLEDColor(ledRed);
	playSoundFile("Magic Wand");
	setMotorSpeed(hoejre,20);
	setMotorSpeed(venstre,20);
	sleep(400);
}

void brudtStreg1a()
{
	setLEDColor(ledOrange);
	setMotorSpeed(venstre,45);              //drejer bl�dt til h�jre
	setMotorSpeed(hoejre, 15);
	sleep(1000);
	setMotorSpeed(venstre,15);              //drejer lidt til venstre (finder linjen igen)
	setMotorSpeed(hoejre, 55);
	sleep(500);
}

void brudtStreg1b()
{
	setLEDColor(ledGreen);
	setMotorSpeed(venstre, 15);             //drejer til venstre
	setMotorSpeed(hoejre,65);
	sleep(500);
	setMotorSpeed(venstre,35);              //drejer til h�jre
	setMotorSpeed(hoejre, 15);
	sleep(500);
	setMotorSpeed(venstre,20);              //drejer lidt til venstre igen
	setMotorSpeed(hoejre, 25);
	sleep(1150);                            //er l�ngere end 1a, fordi den skal ende p� venstre side af den sorte streg.
}


void drejTilHojre2()
{
	setMotorSpeed(venstre, 20);
	setMotorSpeed(hoejre, 20);
	sleep(800);
	setMotorSpeed(venstre,30);				      //drejer i 0,8 sek
	setMotorSpeed(hoejre,-15);
	sleep(800);
	setMotorSpeed(venstre,0);
	setMotorSpeed(hoejre,0);
	playSoundFile("Lift load");             //robot-lyde :)
	setMotorTarget(arm,-700,30); 	      		//arme koerer ned og aabner
	sleep(2000);
}

void loeftFlaske2()
{
	setMotorSpeed(venstre,0);              //stopper ved flasken (afstand i main prog.)
	setMotorSpeed(hoejre,0);
	playSoundFile("Lift load");
	setMotorTarget(arm,700,30);            //l�fter arm & flaske.
	sleep(2000);
	setMotorSpeed(venstre, 10);            //k�rer frem i 3.1 sek, og s�tter flasken (p� den anden side af den sorte streg).
	setMotorSpeed(hoejre, 10);
	sleep(3100);
}

void afleverFlaske2()
{
	setLEDColor(ledRedFlash);
	setMotorSpeed(venstre,0);
	setMotorSpeed(hoejre,0);
	playSoundFile("Lift load");
	setMotorTarget(arm,-700,30);            //s�nker arm og flaske
	sleep(2000);
	setMotorSpeed(venstre, 5);
	setMotorSpeed(hoejre, 5);
	sleep(1200);                            //k�rer lidt frem for at rette flasken op, hvis den bliver sat sk�vt ned
	setMotorSpeed(venstre, -10);
	setMotorSpeed(hoejre, -10);
	sleep(3000);
	playSoundFile("Lift load");
	setMotorTarget(arm,700,50);       			//loefter arme igen
	sleep(3000);
	setMotorSpeed(venstre,-30);             //drejer om sig selv mod h�jre; ca. 135 grader
	setMotorSpeed(hoejre,30);
	sleep(1000);
	setMotorSpeed(venstre,40);              //k�rer ligeud i 1 sek.
	setMotorSpeed(hoejre,40);
	sleep(1000);
	setMotorSpeed(venstre,20);              //tilbage til banen, retter ind p� linjen igen.
	setMotorSpeed(hoejre,-20);
	sleep(400);
}
/*
void forhindring3a()                      //Den fam�se vippe:
{
setMotorSpeed(hoejre,20);
setMotorSpeed(venstre,20);              //k�rer lidt frem
sleep(600);
setMotorSpeed(venstre,-15);             //drejer i 0,65 sek for at finde gr� streg (f�lger svinget).
setMotorSpeed(hoejre,30);
sleep(650);
}
void forhindring3b()
{
setMotorSpeed(hoejre, -10);             //bakker lidt for at rette op.
setMotorSpeed(venstre, -10);
sleep(1000);
turn180();                              //kalder turn 180 (den drejer 180grader)...
setMotorSpeed(hoejre,0);
setMotorSpeed(venstre,0);
sleep(300);
setMotorSpeed(hoejre,-100);             //bakker med FULD fart, s� den kan komme op p� vippen.
setMotorSpeed(venstre,-100);
sleep(4200);                            // i 4.2 sekunder - det er den tid det tager at k�re over vippen med 100% fart.
turn90();
}*/

void forhindring4()
{
	setLEDColor(ledOrangeFlash);
	setMotorSpeed(venstre,25);              // drejer bl�dt til venstre.
	setMotorSpeed(hoejre,30);
	sleep(3800);
	setMotorSpeed(venstre,20);              //drejer til h�jre efter den har k�rt over de f�rste tre gr� streger.
	setMotorSpeed(hoejre,0);								// for at rette op.
	sleep(400);
}


void udModMaalskive5()
{
	setMotorSpeed(hoejre,25);               //drejer mod venstre, f�lger svinget.
	setMotorSpeed(venstre,0);
	sleep(1500);
}

void henteFlaske5()
{
	setMotorSpeed(hoejre,28);               //frem til midten af bullseye
	setMotorSpeed(venstre,30);
	sleep(2800);

	setMotorTarget(arm,-700,60);            //saenker arm
	setMotorSpeed(venstre,0);
	setMotorSpeed(hoejre,0);
	sleep(800);

}

void findFlaske5()
{
	while(getUSDistance(ultra)>60)          //s�ger efter flaske
	{
		setMotorSpeed(venstre,-5);
		setMotorSpeed(hoejre,5);
	}
	setMotorSpeed(venstre,-5);              //drejer lidt ekstra, da sensoren ikke sidder helt i midten :)
	setMotorSpeed(hoejre,5);
	sleep(400);
	setMotorSpeed(venstre,0);
	setMotorSpeed(hoejre,0);
	sleep(1000);
	while(getUSDistance(ultra)>6)           //k�rer frem, mens indtil afstanden er mindre end 6cm.
	{
		setMotorSpeed(venstre,20);
		setMotorSpeed(hoejre,20);
	}
}
void loeftFlaske5()
{
	setMotorSpeed(venstre,0);               //lukker armene om flasken
	setMotorSpeed(hoejre,0);
	setMotorTarget(arm,700,50);
	sleep(2000);                            //det tager ca 2 sekunder
}

void smidFlaske5()                      //stopper og smider flaske
{
	setMotorSpeed(venstre,0);
	setMotorSpeed(hoejre,0);
	setMotorTarget(arm,-700,50);          //s�nker arm og flaske
	sleep(2000);
	setMotorSpeed(venstre, 10);           //retter flaske, k�rer lidt frem
	setMotorSpeed(hoejre, 10);
	sleep(500);
}

void bakMedFlaske5()                      //tilbage og s�t flaske
{
	setMotorSpeed(hoejre,-35);              //bakker tilbage, s�tter flasken
	setMotorSpeed(venstre,-35);
	sleep(1900);
	smidFlaske5();
	setMotorSpeed(hoejre,-25);              //bakker v�k fra flasken.
	setMotorSpeed(venstre,-25);
	setMotorTarget(arm,700,50);             //og l�fter armene
	sleep(3000);
	setMotorSpeed(venstre,-55);	            //vender  p� stedet
	setMotorSpeed(hoejre,55);
	sleep(550);
}

void tilbageTilGraa5()
{             														//finder gr� linje og drejer til venstre
	setMotorSpeed(venstre, 0);
	setMotorSpeed(hoejre, 0);
	sleep(1000);
	while(SensorValue(lys)>85)              //k�rer ligeud mens banen er hvid
	{
		setLEDColor(ledGreenFlash);
		setMotorSpeed(hoejre,50);
		setMotorSpeed(venstre,50);
	}
	sleep(200);
	setMotorSpeed(hoejre,25);               //banen er gr�, drejer til venstre
	setMotorSpeed(venstre,-25);
	sleep(700);
}

void rundtOmFlaske6a()
{
	setMotorSpeed(venstre,10);              //drejer p� stedet til h�jre
	setMotorSpeed(hoejre,-10);
	sleep(1000);
	setMotorSpeed(venstre,40);              //k�rer fremad
	setMotorSpeed(hoejre,40);
	sleep(1000);
	setMotorSpeed(venstre,-10);             //drejer p� stedet til venstre
	setMotorSpeed(hoejre,10);
	sleep(1000);
	setMotorSpeed(venstre,40);              //k�rer fremad
	setMotorSpeed(hoejre,40);
	sleep(1000);
	setMotorSpeed(venstre,10);              //drejer bl�dt til venstre
	setMotorSpeed(hoejre,20);
	sleep(2300);
	setMotorSpeed(venstre,30);              //drejer til h�jre (for at rette ind)
	setMotorSpeed(hoejre,12);
	sleep(1500);

}
void rundtOmFlaske6b()                    //dette program vender modsat ovenst�ende fordi robotten skal ende p� den anden side af linjen.
{
	setMotorSpeed(venstre,-10);             //drejer til venstre
	setMotorSpeed(hoejre,10);
	sleep(1000);
	setMotorSpeed(venstre,40);              //k�rer frem
	setMotorSpeed(hoejre,40);
	sleep(1000);
	setMotorSpeed(venstre,10);              //drejer til h�jre
	setMotorSpeed(hoejre,-10);
	sleep(1000);
	setMotorSpeed(venstre,40);              //k�rer frem
	setMotorSpeed(hoejre,40);
	sleep(1000);
	setMotorSpeed(venstre,20);              //drejer bl�dt til h�jre
	setMotorSpeed(hoejre,10);
	sleep(1500);
	setMotorSpeed(venstre,12);              //drejer til venstre,retter ind.
	setMotorSpeed(hoejre,30);
	sleep(1500);
}

void udfordring7a ()
{
	setMotorSpeed(hoejre,-10);
	setMotorSpeed(venstre,-10);
	sleep(5000);
}
void udfordring7b()
{
	setMotorSpeed(hoejre,30);  	//K�r lige ud
	setMotorSpeed(venstre,30);
	sleep(2100);

	setMotorSpeed(hoejre,15); 	//Drej venstre
	setMotorSpeed(venstre,-15);
	sleep(700);

	setMotorSpeed(hoejre,15);		//K�r lige ud
	setMotorSpeed(venstre,15);
	sleep(2000);

	setMotorSpeed(hoejre,-15);	//Drej h�jre
	setMotorSpeed(venstre,15);
	sleep(700);

	setMotorSpeed(hoejre,15);		//K�re lige ud
	setMotorSpeed(venstre,15);
	sleep(1500);

	setMotorSpeed(hoejre,-15);	//Drej h�jre
	setMotorSpeed(venstre,15);
	sleep(800);

	setMotorSpeed(hoejre,20);		//K�r lige ud
	setMotorSpeed(venstre,20);
	sleep(2000);

	setMotorSpeed(hoejre,15); 	//Drej venstre
	setMotorSpeed(venstre,-15);
	sleep(950);

	setMotorSpeed(hoejre,20);		//K�r lige ud
	setMotorSpeed(venstre,20);
	sleep(3000);

}

void findVenstreStreg8()                  //finder venstre streg p� landingsbanen & f�lger den.
{
	setLEDColor(ledGreenFlash);
	setMotorSpeed(hoejre,10);               //drejer p� stedet til venstre
	setMotorSpeed(venstre,-10);
	sleep(1000);

	setMotorSpeed(hoejre,30);               //k�rer frem
	setMotorSpeed(venstre,30);
	sleep(1000);

	setMotorSpeed(hoejre,-10);              //drejer til h�jre; s� den finder linjen.
	setMotorSpeed(venstre,10);
	sleep(1000);
}

void landingsbanen8()
{                                         //har brug for dette; bruger en timer i main prog.
	while(SensorValue(lys)>30&&SensorValue(lys)<87)
	{
		koerGraa();
	}
	while(SensorValue(lys)>87)
	{
		koerHvid();
	}
}

void midtPaaBanen8()                      //finder midten af landingsbanen vha ultralyd, drejer ind.
{
	setLEDColor(ledRedFlash);
	setMotorSpeed(hoejre,0);                //stopper midt p� banen (efter 11.7 sek; se timer i main prog.)
	setMotorSpeed(venstre,0);
	sleep(200);

	setMotorSpeed(hoejre,-12);              //drejer til h�jre, ca 90 grader
	setMotorSpeed(venstre,12);
	sleep(1500);

	setMotorSpeed(hoejre,5);                //k�rer laaangsomt frem til midten af landingsbanen
	setMotorSpeed(venstre,5);
	sleep(4300);

	setMotorSpeed(hoejre,0);                //stopper, og sleep i lang tid. her skal der inds�ttes noget musik senere
	setMotorSpeed(venstre,0);
	sleep(10000000000);
}


task main()
{
	setSoundVolume(100);
	playSoundFile("Motor start");           //robotlyde :)
	sleep(1000);
	while(true)
	{
		if(SensorValue(lys)<30) 							//registrerer sort
		{
			registrerSort();                    //opt�ller sort, s� robotten ved hvor den er p� banen
			sort = sort +1;
		}

		else if (sort==1)                     //hvis sort==1 kaldes udfordring 1a
		{
			brudtStreg1a();
			sort = sort + 1;                    //l�gger en til sort, s� den kommer ud af udfordring 1a.
		}                                     //resten fungerer p� samme princip

		else if (sort==3)
		{
			brudtStreg1b();
			sort = sort +1;
		}


		else if (sort==5)
		{
			drejTilHojre2();						//Start void udfordring 2
			sort = sort + 1;
		}
		//hvis afstanden er under 5, og sort er 6, kaldes loeftFlaske2
		else if (getUSDistance(ultra)<5 && sort==6)
		{
			loeftFlaske2();
			sort=sort+1;
		}

		else if(sort==7)
		{
			afleverFlaske2();			//slut void udfordring 2
			sort=sort+1;
		}

		else if(sort==10)
		{
			forhindring4();     // udf�r udfordring 4
			sort=sort+1;
		}

		else if(sort==12)
		{
			udModMaalskive5();  // udf�r udfordring 5
			sort=sort+1;
		}

		else if(sort==14)
		{
			henteFlaske5();
			sort=sort+1;
		}

		else if(sort==15)
		{
			findFlaske5();
			sort=sort+1;
		}

		else if (sort==16)
		{
			sleep(500);
			loeftFlaske5();                     //oplevede problemer med flere registreringer af sort, s� derfor sleep udenfor void
			sleep(500);
			setMotorSpeed(venstre,-30);         //samme princip, k�rer v�k fra sort
			setMotorSpeed(hoejre,-30);
			sleep(1000);
			sort=sort+1;
		}

		else if (sort==17)
		{
			bakMedFlaske5();
			sort=sort+1;
		}

		else if(sort==18)
		{
			tilbageTilGraa5();
			sort=sort+1;
		}

		else if (sort==20)
		{
			rundtOmFlaske6a();
			sort=sort+1;
		}

		else if (sort==22)
		{
			clearTimer(T1);                     //genstarter uret inden brug
			while(time1[T1]<2)                  //uret s�ttes til 2 sekunder. Hanne retter op
			{
				while(SensorValue(lys)>30&&SensorValue(lys)<80)
				{
					setMotorSpeed(hoejre,10);
					setMotorSpeed(venstre,3);
				}
				while(SensorValue(lys)>80)
				{
					setMotorSpeed(hoejre,3);
					setMotorSpeed(venstre,10);
				}
			}
			sort=sort+1;
		}



		else if (sort==25)
		{
			rundtOmFlaske6b();
			sort=sort+1;
		}

		else if(sort==27)
		{
			udfordring7a();		// start void udfordringa 7
			sleep(200);
			sort=sort+1;
		}

		else if(sort==28)
		{

			while(SensorValue(lys)>30&&SensorValue(lys)<80)
			{
				koerGraa2();
			}
			while(SensorValue(lys)>80)
			{
				koerHvid2();
			}

		}

		else if(sort==29)
		{
			udfordring7b();			//slut void udfordringb 7
			sort=sort+1;
		}


		else if(sort==31)
		{
			findVenstreStreg8();
			sort=sort+1;
		}

		else if(sort==32)
		{
			clearTimer(T1);                     //genstarter uret inden brug
			while(time1[T1]<11700)              //uret s�ttes til 11.7 sekunder - det passer med at robotten er midt p� landingsbanen
			{	landingsbanen8();
			}
			sort=sort+1;
		}

		else if(sort==33)
		{
			midtPaaBanen8();
		}

		else                                  //hvis ikke noget af ovenst�ende er g�ldende, f�lger den linjen med f�lgende kommando
		{
			while(SensorValue(lys)>30&&SensorValue(lys)<85)
			{
				koerGraa();                       //hvis banen er gr� (lysv�rdier ml. 30 & 85) kaldes koerGraa
			}
			while(SensorValue(lys)>85)
			{
				koerHvid();                       //hvis banen er hvid (lysv�rdier over 85) kaldes koerHvid
			}
		}
	}
}                                         //vinder RoboCup :)
