class CityStoreMission extends SurvivorMissions
{	//CityStore is a copy of UrbanMall mission, it uses another secondary mission building
	
	//Mission related entities 
	Car MissionCar;
	Object MissionBuilding;
	ItemBase MissionObject;
	ref TStringArray FoodTypes = {"SpaghettiCan","BakedBeansCan","SardinesCan","TunaCan","PeachesCan","TacticalBaconCan","Marmalade"};
	
	//Mission parameters
	int ReqFoodAmount = 10;					//cans of food 
	int ReqMedAmount = 4;					//packets of antibiotics
	int ExtendedTimout = 1800;				//seconds, mission duration time for extended mission
	int MsgDlyFinish = 60;					//seconds, message delay time after player has finished mission
	
	//Mission containers
	ref array<vector> ExtendedPosList = new array<vector>;
	ref array<vector> MedSpawns = new array<vector>;
	ref array<vector> FoodSpawns = new array<vector>;
	ref array<vector> PriInfectSpawns = new array<vector>;
	ref array<vector> SecInfectSpawns = new array<vector>;
	ref array<string> InfectedTypes = new array<string>;
	ref array<ref Param3<string,vector,vector>> Barricades = new array<ref Param3<string,vector,vector>>;

	
	//Mission variables 
	vector Offset = "-1.351 0.00 0.824";				//Offset vector of all spawn positions of primary mission
	vector TargetPosition = "-5.3 -1.2 1.9";
	vector RewardsPosition = "-3.46 -5.72 6.63";
	string SurvivorName;	
	
	bool IsExtended() return true;
	
	void CityStoreMission()
	{		
		//Select primary mission
		m_MissionExtended = true;
		
		//Mission timeout
		m_MissionTimeout = 2700;			//seconds, primary mission duration time
		
		//Mission zones
		m_MissionZoneOuterRadius = 100.0;	//meters (!Do not set lower than 200m), mission activation distance
		m_MissionZoneInnerRadius = 3.7;		//meters (!Do not set outside of 1-5m), mission finishing distance to target object
				
		//Mission informant
		m_MissionInformant = "Dr. Legasov";
	
		//Mission person names
		TStringArray SurvivorNames = {"Tamarova", "Lorzinski", "Blosmanova", "Gabarin", "Sloskova", "Belzin", "Homyuk", "Trademzyuk", "Jankarova"};
		SurvivorName = SurvivorNames.GetRandomElement();
		
		//Set mission messages for primary mission
		m_MissionMessage1 = "Ms. "+ SurvivorName +", a ground school teacher, told me that she has brought some children of her class in safety from their infected families. I promised that i will help her for getting food and other medical supplies for the kids.";
		m_MissionMessage2 = "Yesterday I found out that the city store\n** "+ m_MissionLocationDir +" of "+ m_MissionLocation +" **\nis barricaded and probably has some food inside. But there were too many infected around, i wasn't able to check the Supermarket.";
		m_MissionMessage3 = "She immediately needs following things:\n- "+ ReqFoodAmount +" cans of food\n- "+ ReqMedAmount +" packets of antibiotics\nPlease help me to support Ms. "+ SurvivorName +" with these life essentials for the kids. Be careful!";
		
		//Spawnpoints for antibiotics in store (cash desk)
		MedSpawns.Insert("-5.392 -0.686 1.087" - Offset );
		MedSpawns.Insert("-5.836 -0.686 1.087" - Offset );
		MedSpawns.Insert("-5.865 -0.686 2.964" - Offset );
		MedSpawns.Insert("-5.051 -0.686 3.033" - Offset );
		MedSpawns.Insert("-5.092 -0.686 1.087" - Offset );
				
		//Spawnpoints for food in store (shelves)
		FoodSpawns.Insert("10.9 0.061 0.019" - Offset );
		FoodSpawns.Insert("10.9 0.061 0.857" - Offset );
		FoodSpawns.Insert("10.9 0.061 2.525" - Offset );
		FoodSpawns.Insert("10.9 0.061 3.195" - Offset );
		FoodSpawns.Insert("10.9 -0.280 0.119" - Offset );
		FoodSpawns.Insert("10.9 -0.621 0.219" - Offset );
		FoodSpawns.Insert("10.5 0.061 0.019" - Offset );
		FoodSpawns.Insert("10.5 -0.280 0.857" - Offset );
		FoodSpawns.Insert("10.5 -0.621 2.525" - Offset );
		FoodSpawns.Insert("10.5 0.061 3.195" - Offset );				
				
		//Infected spawnpoints for primary mission
		//indoor
		PriInfectSpawns.Insert("-8.4 0 -1.2" - Offset );	//dead
		PriInfectSpawns.Insert("-3.8 0 -1.3" - Offset );	//dead
		PriInfectSpawns.Insert("-7.4 0 2" - Offset );		//dead 
		PriInfectSpawns.Insert("12.2 0 1.5" - Offset );
		PriInfectSpawns.Insert("10.5 0 -6.7" - Offset );
		//outdoor
		PriInfectSpawns.Insert("-13.2 0 -6.5" - Offset );
		PriInfectSpawns.Insert("-13.6 0 2.8" - Offset );
		PriInfectSpawns.Insert("-8.57 0 7.3" - Offset );
		PriInfectSpawns.Insert("-0.47 0 10.13" - Offset );
		PriInfectSpawns.Insert("10.4 0 10" - Offset );
		PriInfectSpawns.Insert("-7.5 0 -11" - Offset );
		PriInfectSpawns.Insert("5.7 0 -12" - Offset );
		
		//Infected spawnpoints for secondary mission 
		//indoor 1st floor
		SecInfectSpawns.Insert("-7.81 -2.55 -4.34");	//policeman in quiet room
		SecInfectSpawns.Insert("-4.5 -2.55 -1.07");		//policeman in office 
		SecInfectSpawns.Insert("7.33 -2.55 -3.68");		//policeman in back office
		SecInfectSpawns.Insert("2.44 -2.55 -2.31");		//interrogated
		//indoor 2nd floor
		SecInfectSpawns.Insert("2.68 -6.35 5.97");		//arrested
		SecInfectSpawns.Insert("3.63 -6.35 5.32");		//arrested
		SecInfectSpawns.Insert("3.89 -6.35 4.51");		//arrested
		SecInfectSpawns.Insert("3.94 -6.35 3.5");		//arrested
		//outdoor
		SecInfectSpawns.Insert("-5.7 0 -11.2");
		SecInfectSpawns.Insert("-7.0 0 7.7");
		SecInfectSpawns.Insert("5.6 0 7.1");
		SecInfectSpawns.Insert("4.5 0 -8.3");
	
		//Infected types for primary and secondary mission position
		//Male												//Female
		InfectedTypes.Insert("ZmbM_CitizenASkinny_Brown");	InfectedTypes.Insert("ZmbF_JournalistNormal_White");
		InfectedTypes.Insert("ZmbM_priestPopSkinny");		InfectedTypes.Insert("ZmbF_Clerk_Normal_White");
		InfectedTypes.Insert("ZmbM_HermitSkinny_Beige");	InfectedTypes.Insert("ZmbF_CitizenANormal_Blue");
		InfectedTypes.Insert("ZmbM_CitizenBFat_Red");		InfectedTypes.Insert("ZmbF_CitizenBSkinny");
		InfectedTypes.Insert("ZmbM_FishermanOld_Green");	InfectedTypes.Insert("ZmbF_HikerSkinny_Grey");
		InfectedTypes.Insert("ZmbM_HunterOld_Autumn");		InfectedTypes.Insert("ZmbF_SurvivorNormal_Orange");
		InfectedTypes.Insert("ZmbM_CitizenBFat_Blue");		InfectedTypes.Insert("ZmbF_HikerSkinny_Green");
		InfectedTypes.Insert("ZmbM_MotobikerFat_Black");	InfectedTypes.Insert("ZmbF_JoggerSkinny_Green");
		InfectedTypes.Insert("ZmbM_JoggerSkinny_Red");		InfectedTypes.Insert("ZmbF_SkaterYoung_Striped");
		InfectedTypes.Insert("ZmbM_MechanicSkinny_Grey");	InfectedTypes.Insert("ZmbF_BlueCollarFat_Red");
		InfectedTypes.Insert("ZmbM_HandymanNormal_Green");	InfectedTypes.Insert("ZmbF_MechanicNormal_Beige");
		InfectedTypes.Insert("ZmbM_HeavyIndustryWorker");	InfectedTypes.Insert("ZmbF_PatientOld");
		InfectedTypes.Insert("ZmbM_Jacket_black");			InfectedTypes.Insert("ZmbF_ShortSkirt_beige");
		InfectedTypes.Insert("ZmbM_Jacket_stripes");		InfectedTypes.Insert("ZmbF_VillagerOld_Red");
		InfectedTypes.Insert("ZmbM_HikerSkinny_Blue");		InfectedTypes.Insert("ZmbF_JoggerSkinny_Red");
		InfectedTypes.Insert("ZmbM_HikerSkinny_Yellow");	InfectedTypes.Insert("ZmbF_MilkMaidOld_Beige");
		InfectedTypes.Insert("ZmbM_PolicemanFat");			InfectedTypes.Insert("ZmbF_VillagerOld_Green");
		InfectedTypes.Insert("ZmbM_PatrolNormal_Summer");	InfectedTypes.Insert("ZmbF_ShortSkirt_yellow");
		InfectedTypes.Insert("ZmbM_JoggerSkinny_Blue");		InfectedTypes.Insert("ZmbF_NurseFat");
		InfectedTypes.Insert("ZmbM_VillagerOld_White");		InfectedTypes.Insert("ZmbF_PoliceWomanNormal");
		InfectedTypes.Insert("ZmbM_SkaterYoung_Brown");		InfectedTypes.Insert("ZmbF_HikerSkinny_Blue");
		InfectedTypes.Insert("ZmbM_MechanicSkinny_Green");	InfectedTypes.Insert("ZmbF_ParamedicNormal_Green");
		InfectedTypes.Insert("ZmbM_DoctorFat");				InfectedTypes.Insert("ZmbF_JournalistNormal_Red");
		InfectedTypes.Insert("ZmbM_PatientSkinny");			InfectedTypes.Insert("ZmbF_SurvivorNormal_White");
		InfectedTypes.Insert("ZmbM_ClerkFat_Brown");		InfectedTypes.Insert("ZmbF_JoggerSkinny_Brown");
		InfectedTypes.Insert("ZmbM_ClerkFat_White");		InfectedTypes.Insert("ZmbF_MechanicNormal_Grey");
		InfectedTypes.Insert("ZmbM_Jacket_magenta");		InfectedTypes.Insert("ZmbF_BlueCollarFat_Green");
		InfectedTypes.Insert("ZmbM_PolicemanSpecForce");	InfectedTypes.Insert("ZmbF_DoctorSkinny");
		
		//Shop barricades  (view from inside building!)
		//shopwindow bottom line  (from right to left) 
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "11.24 -0.05 5.97" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "9.98 -0.05 5.97" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "8.72 -0.05 5.97" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "7.46 -0.05 5.97" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "6.2 -0.05 5.97" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "4.94 -0.05 5.97" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "3.68 -0.05 5.97" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "2.42 -0.05 5.97" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "1.16 -0.05 5.97" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "-0.1 -0.05 5.97" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "-1.36 -0.05 5.97" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "-2.62 -0.05 5.97" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "-3.88 -0.05 5.97" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "-5.14 -0.05 5.97" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "-6.4 -0.05 5.97" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("Land_Boat_Small1", "10.0 0.9 5.9" - Offset , "0 110 0"));
		Barricades.Insert( new Param3<string,vector,vector>("Land_Boat_Small1", "7.0 0.9 5.9" - Offset , "0 110 0"));
		Barricades.Insert( new Param3<string,vector,vector>("Land_Boat_Small1", "4.0 0.9 5.9" - Offset , "0 110 0"));
		Barricades.Insert( new Param3<string,vector,vector>("Land_Boat_Small1", "1.0 0.9 5.9" - Offset , "0 110 0"));
		Barricades.Insert( new Param3<string,vector,vector>("Land_Boat_Small1", "-2.0 0.9 5.9" - Offset , "0 110 0"));
		Barricades.Insert( new Param3<string,vector,vector>("Land_Boat_Small1", "-5.0 0.9 5.9" - Offset , "0 110 0"));
		//shopwindow top line  (from right to left)
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "11.24 1.21 5.97" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "9.98 1.21 5.97" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "8.72 1.21 5.97" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "7.46 1.21 5.97" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "6.2 1.21 5.97" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "4.94 1.21 5.97" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "3.68 1.21 5.97" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "2.42 1.21 5.97" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "1.16 1.21 5.97" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "-0.1 1.21 5.97" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "-1.36 1.21 5.97" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "-2.62 1.21 5.97" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "-3.88 1.21 5.97" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "-5.14 1.21 5.97" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "-6.4 1.21 5.97" - Offset , "0 90 0"));
		//shopwindow small 
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-8.370 0.11 6.03" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-9.622 0.11 6.03" - Offset , "0 -90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-7.764 0.31 6.03" - Offset , "180 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-9.642 0.31 6.03" - Offset , "180 -90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-8.370 0.51 6.03" - Offset , "180 -90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-9.622 0.51 6.03" - Offset , "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-8.070 0.72 6.03" - Offset , "0 -90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-9.322 0.72 6.03" - Offset , "180 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-8.370 0.93 6.03" - Offset , "0 -90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-9.622 0.93 6.03" - Offset , "180 -90 0"));				
		//shop entrance		
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "-10.436 -0.602 4.070" - Offset , "90 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "-10.436 -0.602 2.810" - Offset , "90 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "-10.236 -0.602 1.560" - Offset , "75 85 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "-10.436 0.658 4.070" - Offset , "90 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "-10.436 0.658 2.810" - Offset , "90 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("MetalPlate", "-10.236 0.658 1.560" - Offset , "75 95 0"));
		Barricades.Insert( new Param3<string,vector,vector>("Land_Roadblock_Table", "-10.036 -0.252 4.070" - Offset , "0 0 -90"));
		Barricades.Insert( new Param3<string,vector,vector>("Land_Roadblock_Table", "-10.036 -0.252 2.970" - Offset , "0 0 -90"));
		Barricades.Insert( new Param3<string,vector,vector>("Land_Roadblock_WoodenCrate", "-10.0 -0.852 3.520" - Offset , "0 0 0"));
		Barricades.Insert( new Param3<string,vector,vector>("Land_Roadblock_WoodenCrate", "-9.69 -0.882 1.7" - Offset , "-30 0 0"));
		Barricades.Insert( new Param3<string,vector,vector>("Land_Roadblock_WoodenCrate", "-9.59 -0.262 1.7" - Offset , "-32 0 5"));
		//other stuff, dead survivor related 
		Barricades.Insert( new Param3<string,vector,vector>("AdvancedImprovisedShelterPitched", "7.84 -1.18149 1.39" - Offset , "-90 0 0"));
		Barricades.Insert( new Param3<string,vector,vector>("PissGround", "-10.26 -1.200 -8.08" - Offset , "180 0 0"));
		
		//Search for mission building at primary mission position	
		GetGame().GetObjectsAtPosition( m_MissionPosition , 1.0 , m_ObjectList , m_ObjectCargoList );
		for ( int i = 0 ; i < m_ObjectList.Count(); i++ )
		{ 
			Object FoundObject = m_ObjectList.Get(i);
			if ( FoundObject.GetType() == "Land_City_Store_WithStairs" )
			{	
				MissionBuilding = FoundObject;			 
				Print("[SMM] MissionBuilding is "+ MissionBuilding.GetType() +" at "+ m_MissionDescription[2] +" of "+ m_MissionDescription[1] +" @ "+ MissionBuilding.GetPosition() );
				break;
			}	
		}
		if ( !MissionBuilding ) Print("[SMM] City store couldn't be found. Mission rejected!");
		else
		{
			//Close all store doors
			Building Store = Building.Cast( MissionBuilding );
			for ( int j=0; j < 5; j++ ) 
			{
				if ( Store.IsDoorOpen(j) ) Store.CloseDoor(j);
				if ( !Store.IsDoorLocked(j) ) Store.LockDoor(j); 
			}	
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( GetGame().UpdatePathgraphRegionByObject, 1000, false, Store );		
		}			
	}
	
	void ~CityStoreMission()
	{	
		//Despawn all remaining mission objects
		if ( m_MissionObjects )
		{
			Print("[SMM] Despawning "+ m_MissionObjects.Count() +" mission objects from old mission...");		
			for ( int i = 0; i < m_MissionObjects.Count(); i++ )
			{				
				if ( !m_MissionObjects.Get(i))	continue;
				else GetGame().ObjectDelete( m_MissionObjects.Get(i) );			
			}
			m_MissionObjects.Clear();
		}
		
		
		//Delete mission AI's
		if ( m_MissionAIs )
		{
			if ( m_MissionAIs.Count() > 0 )
			{
				Print("[SMM] Despawning "+ m_MissionAIs.Count() +" mission AI's from old mission...");
				for ( int k = 0; k < m_MissionAIs.Count(); k++ )
				{
					GetGame().ObjectDelete( m_MissionAIs.Get(k) );
				}
				m_MissionAIs.Clear();			
			}
			else Print("[SMM] No mission AI's to despawn.");
		}
		
		//Delete PlayersInZone list & reset container takeaway
		if ( m_PlayersInZone )	m_PlayersInZone.Clear();
		if ( m_ContainerWasTaken ) m_ContainerWasTaken = false;
	}
	
	void SpawnSupplies()
	{		
		if ( m_MissionExtended )
		{
			//Spawn antibiotics
			for ( int i=0; i < MedSpawns.Count(); i++ )		
			{
				Object Med = GetGame().CreateObject("TetracyclineAntibiotics", MissionBuilding.ModelToWorld("-5.836 -0.216 1.005" - Offset ) ); //safe position
				vector MedPos = MissionBuilding.ModelToWorld( MedSpawns.Get(i) );
				Med.SetPosition( MedPos );
				m_MissionObjects.Insert( Med );
			}
			
			//Spawn cans of food
			for ( int j=0; j < FoodSpawns.Count(); j++ )
			{
				string Can = FoodTypes.GetRandomElement();
				vector CanPos = MissionBuilding.ModelToWorld( FoodSpawns.Get(j) );
				Object CanOfFood = GetGame().CreateObject( Can , CanPos );
				CanOfFood.SetPosition( CanPos );
				m_MissionObjects.Insert( CanOfFood );
			}
			
			//Spawn extra weapon
			Object weapon = GetGame().CreateObject("Mp133Shotgun", MissionBuilding.ModelToWorld("9.67 -1.16 0.53"));
			m_MissionObjects.Insert( weapon );
			weapon = GetGame().CreateObject("Ammo_12gaPellets", MissionBuilding.ModelToWorld("9.57 -1.16 0.63"));
			weapon = GetGame().CreateObject("Ammo_12gaPellets", MissionBuilding.ModelToWorld("9.51 -1.16 0.73"));
		}
		else
		{
			//Spawn orange MountainBag 
			//vector pos = MissionBuilding.ModelToWorld( RewardsPosition );
			MissionObject = ItemBase.Cast( GetGame().CreateObject( "MountainBag_Orange" , m_MissionPosition ));
			m_MissionObjects.InsertAt( MissionObject, 0 );
		} 		
	}
	
	void SpawnRewards()
	{		
		//new MissionObject after deleting orange bag
		MissionObject = ItemBase.Cast( GetGame().CreateObject( "MountainBag_Orange", m_MissionPosition ));
		
		//Get random loadout             
        int selectedLoadout = Math.RandomIntInclusive(0,2);    // Num of loadouts
        
        //Spawn selected loadout items in mission object
        int j = 0;
        for (j = Math.RandomIntInclusive(1,4); j > 0; j--) MissionObject.GetInventory().CreateInInventory( Currency.GetRandomElement() ); //Between 1-4 Random Currency to be made in the seachest.
        for (j = Math.RandomIntInclusive(1,3); j > 0; j--) MissionObject.GetInventory().CreateInInventory( LootTableAmmo.GetRandomElement() );// Pull 1-3 Random Ammo Boxes.
        for (j = Math.RandomIntInclusive(1,3); j > 0; j--) MissionObject.GetInventory().CreateInInventory( LootTableFood.GetRandomElement() );// Pull 1-3 Random Food Items.
        for (j = Math.RandomIntInclusive(1,2); j > 0; j--) MissionObject.GetInventory().CreateInInventory( LootTableMeds.GetRandomElement() );// Pull 1-2 Random Medical Items.
        for (j = Math.RandomIntInclusive(1,1); j > 0; j--) MissionObject.GetInventory().CreateInInventory( LootTableWeaponParts.GetRandomElement() ); // Pull 1 Random Weapon Parts.


        if (selectedLoadout == 0) // If 1 Selected Make 1-3 of Items from Rare Items Table.
        {
            for (j = Math.RandomIntInclusive(1,3); j > 0; j--) MissionObject.GetInventory().CreateInInventory( LootTableRareItems.GetRandomElement() );
        }
        if (selectedLoadout == 1) // If 1 Selected Make 1-2 of Items from Weapons Table.
        {
            for (j = Math.RandomIntInclusive(1,2); j > 0; j--) MissionObject.GetInventory().CreateInInventory( LootTableWeapons.GetRandomElement() );
        }
        if (selectedLoadout == 2) // If 2 Selected Make 1-4 of Items from Basebuilding Table.
        {
            for (j = Math.RandomIntInclusive(1,4); j > 0; j--) MissionObject.GetInventory().CreateInInventory( LootTableBaseBuilding.GetRandomElement() ); 
        }

		Print("[SMM] Mission rewards spawned in reward container. Randomly selected rewards were added plus "+ selectedLoadout +"." );
	}
	
	void SpawnObjects()
	{	
		Object FoundObject;
		
		if ( m_MissionExtended )
		{	//Primary mission is selected
			//New MissionPosition is at cash desk
			m_MissionPosition = MissionBuilding.ModelToWorld( TargetPosition );
	 		
			//Clean up cash desk spawnpoints
			GetGame().GetObjectsAtPosition( m_MissionPosition, 1.5, m_ObjectList, m_ObjectCargoList );
			
			if ( m_ObjectList.Count() > 0)
			{
				for ( int i=0; i < m_ObjectList.Count(); i++)
				{
					FoundObject = m_ObjectList.Get(i);
					if ( FoundObject.IsItemBase() )
					{
						Print("[SMM] BeforeSpawnCleanUp :: Object  " + FoundObject.ToString() + " at new mission position was deleted.");
						GetGame().ObjectDelete( FoundObject );
					}
				}
			}
			
			//Spawn supplies 1 second later			
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( this.SpawnSupplies, 1000 );
			
			//Spawn barricades		
			for ( int j=0; j < Barricades.Count(); j++ )
			{
				Param3<string,vector,vector> BarricadeDef = Barricades.Get(j);
				string BarricadeType = BarricadeDef.param1;
				vector BarricadePos = MissionBuilding.ModelToWorld( BarricadeDef.param2 );
				vector BarricadeOri = BarricadeDef.param3;
				vector BarricadeDir = MissionBuilding.GetDirection();
				Object PlankBarricade;
				
				if ( BarricadeType == "Land_Boat_Small1" )
				PlankBarricade = GetGame().CreateObject( BarricadeType, BarricadePos, true );
				else
				{
					PlankBarricade = GetGame().CreateObject( BarricadeType, BarricadePos );
					if ( BarricadeType == "MetalPlate" || BarricadeType == "WoodenPlank" )
					{						
						ItemBase.Cast( PlankBarricade ).SetQuantity(1);
						ItemBase.Cast( PlankBarricade ).SetTakeable( false );
					}					 
				}
				PlankBarricade.SetPosition( BarricadePos );
				PlankBarricade.SetDirection( BarricadeDir );
				PlankBarricade.SetOrientation( PlankBarricade.GetOrientation() + BarricadeOri );

				m_MissionObjects.Insert( PlankBarricade );
			}
			
			//Spawn dead survivors hideout legacy	
			EntityAI Cooker = EntityAI.Cast( GetGame().CreateObject( "PortableGasStove", MissionBuilding.ModelToWorld("-5.96 -0.2156 0.84" - Offset )));
			Cooker.GetInventory().CreateAttachment("SmallGasCanister");
			Cooker.GetInventory().CreateAttachment("Pot");
			m_MissionObjects.Insert( Cooker );
			
			m_MissionObjects.Insert( GetGame().CreateObject( "Paper", MissionBuilding.ModelToWorld("-9.74 -1.17 -7.49" - Offset )));
			m_MissionObjects.Insert( GetGame().CreateObject( "Paper", MissionBuilding.ModelToWorld("-8.18 -1.17 -8.09" - Offset )));
			m_MissionObjects.Insert( GetGame().CreateObject( "ShitGround", MissionBuilding.ModelToWorld("-9.54 -1.17 -7.69" - Offset )));
			m_MissionObjects.Insert( GetGame().CreateObject( "ShitGround", MissionBuilding.ModelToWorld("-9.34 -1.17 -7.89" - Offset )));
			
			Print("[SMM] Survivor Mission "+ m_selectedMission +" :: "+ m_MissionName +" ...primary mission deployed!");
		}
		else
		{	//Secondary mission is selected
			//New MissionPosition is bed in quiet room 
			m_MissionPosition = MissionBuilding.ModelToWorld( RewardsPosition );
	 		
			//Clean up bed spawnpoint
			GetGame().GetObjectsAtPosition( m_MissionPosition, 1.0, m_ObjectList, m_ObjectCargoList );
			
			if ( m_ObjectList.Count() > 0)
			{
				for ( int k=0; k < m_ObjectList.Count(); k++)
				{
					FoundObject = m_ObjectList.Get(k);
					if ( FoundObject.IsItemBase() )
					{
						Print("[SMM] BeforeSpawnCleanUp :: Object  " + FoundObject.ToString() + " at new mission position was deleted.");
						GetGame().ObjectDelete( FoundObject );
					}
				}
			}
						
			//Spawn mission target orange MountainBag 1 second later			
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( this.SpawnSupplies, 1000 );	
						
			Print("[SMM] Survivor Mission Extension "+ m_selectedMission +" :: "+ m_MissionName +" ...secondary mission deployed!");
		}
	}
	
	void SpawnAIs()
	{	
		string RandomInfected;
		vector InfectedPos;
		int DeadInfectedCount = 3;
		DayZInfected Zed;
				
		if ( !MissionBuilding ) Print("[SMM] Extended Mission : Missionbuilding couldn't be found in "+ m_MissionDescription[3] +"." );		
		else
		{
			if ( m_MissionExtended )
			{
				//Spawn some infected at city store
				for ( int j = 0 ; j < PriInfectSpawns.Count() ; j++ )
				{
		    	   	RandomInfected = InfectedTypes.GetRandomElement();
					InfectedPos = MissionBuilding.ModelToWorld( PriInfectSpawns.Get(j) - Offset );
					Zed = DayZInfected.Cast( GetGame().CreateObject( RandomInfected, InfectedPos, false, true ));
					if ( j < DeadInfectedCount ) Zed.SetHealth("","",0);
					m_MissionAIs.Insert( Zed );
				}
			}
			else
			{
				//Spawn some infected at Police Station
				for ( int k = 0 ; k < SecInfectSpawns.Count() ; k++ )
				{
		    	   	RandomInfected = InfectedTypes.GetRandomElement();
					InfectedPos = MissionBuilding.ModelToWorld( SecInfectSpawns.Get(k) );
					Zed = DayZInfected.Cast( GetGame().CreateObject( RandomInfected, InfectedPos, false, true ));
					m_MissionAIs.Insert( Zed );
				}			
			}
		}
	}
	
	void ObjDespawn() 
	{	
		//Despawn all mission objects at mission timeout except those retains until next mission
		for ( int i = 0; i < m_MissionObjects.Count(); i++ )
		{
			if ( m_MissionObjects.Get(i))
			{
				//Exception: Barricades will remain
				if ( m_MissionObjects.Get(i).GetType() == "MetalPlate" ) continue;
				if ( m_MissionObjects.Get(i).GetType() == "WoodenPlank" ) continue;
				if ( m_MissionObjects.Get(i).GetType() == "Land_Roadblock_Table" ) continue;
				if ( m_MissionObjects.Get(i).GetType() == "Land_Roadblock_WoodenCrate" ) continue;
				if ( m_MissionObjects.Get(i).GetType() == "Land_Boat_Small1" ) continue;
			
				//Delete Object
				GetGame().ObjectDelete( m_MissionObjects.Get(i) );
			}		
		}
	}
	
	void ExtendMission()
	{	//When player enters mission target zone at primary mission

		//Set messages for secondary mission
		m_MissionMessage1 = "Allright you have found the supplies, try to get out there safely. Ms. "+ SurvivorName +" never told me her whereabouts because she wants to be absolutely secure from bandits and scavengers.";
		m_MissionMessage2 = "I think the best will be if you could deposit the supplies in the quiet room of the small\n** "+ m_MissionSecondaryLoc +" ** police station and put all in the orange backpack i left there. I will check it in one hour and try to contact her on radio.";
		m_MissionMessage3 = "I have some things for you at the small police station. Be careful, there might be bandits around "+ m_MissionSecondaryLoc +". They could intercepted our little radio talk here. Good luck!";
		
		//init Messenger for new messages
		m_MsgNum = 1;					//skip msg 0, begin with msg 1
		m_MsgChkTime = m_MissionTime;
		MsgCutoff = false;
		
		//increase mission MissionTimeout for secondary mission
		m_MissionTimeout = m_MissionTime + ExtendedTimout;  
		
		//deployment settings & init for secondary mission		
		m_MissionZoneOuterRadius = 80.0;
		m_MissionZoneInnerRadius = 2.0;
		
		//Get secondary mission position
		if ( EventsWorldData.GetBuildingsAtLoc("Land_Village_PoliceStation", m_MissionDescription[3], ExtendedPosList ))
		m_MissionPosition = ExtendedPosList.GetRandomElement();
		else Print("[SMM] Can't get secondary MissionPosition in "+ m_MissionDescription[3] +" from EventsWorldData!");
		
		//Search for mission building at old mission position and spawn 2. wave of infected
		GetGame().GetObjectsAtPosition( m_MissionPositions.Get( m_selectedMission ) , 1.0 , m_ObjectList , m_ObjectCargoList );
		for ( int i = 0 ; i < m_ObjectList.Count(); i++ )
		{ 
			Object FoundObject = m_ObjectList.Get(i);
			if ( FoundObject.GetType() == "Land_City_Store_WithStairs")
			{	
				Object Store = FoundObject;			 
				//Spawn infected at store outdoor
				for ( int j = 5 ; j < PriInfectSpawns.Count() ; j++ )
				{
		    	   	string RandomInfected = InfectedTypes.GetRandomElement();
					vector InfectedPos = Store.ModelToWorld( PriInfectSpawns.Get(j) );
					DayZInfected Zed = DayZInfected.Cast( GetGame().CreateObject( RandomInfected, InfectedPos, false, true ));
					m_MissionAIs.Insert( Zed );
				}
				
				break;
			}	
		}			
	}
	
	void MissionFinal()
	{	//When player enters last mission target zone
		
		//Spawn second wave of infected at secondary mission
		SpawnAIs();				
	}
	
	void PlayerChecks( PlayerBase player )
	{
		//Check if container gets taken from player
		if ( MissionSettings.Opt_DenyObjTakeaway && !m_MissionExtended )
		{
			if ( m_MissionObjects[0] && m_MissionObjects[0].ClassName() == "MountainBag_Orange" )
			{
				if ( player.GetInventory().HasEntityInInventory( EntityAI.Cast( m_MissionObjects[0] ) ) && !m_ContainerWasTaken )
				{
					m_ContainerWasTaken = true;
					Print("[SMM] Mission object container was taken by a player ...and will be deleted.");
					GetGame().ObjectDelete( m_MissionObjects[0] );
				}
			}
		}
		
		//Check if container has desired amount of mushrooms collected at primary mission position
		if ( MissionObject && MissionObject.ClassName() == "MountainBag_Orange" && !m_MissionExtended )
		{
			int LastCount = 0;
			int CargoCount = MissionObject.GetInventory().CountInventory();			
			int FoundMedObjects = 0;
			int FoundFoodObjects = 0;
			
			if ( CargoCount != LastCount )
			{
				if ( CargoCount >= ReqFoodAmount + ReqMedAmount && FoundMedObjects <= ReqMedAmount && FoundFoodObjects <= ReqFoodAmount )
				{	Print("[SMM] Cargo check OK. Foodcount: "+ FoundFoodObjects +", Medcount: "+ FoundMedObjects );
					
					CargoBase CargoItems1 = MissionObject.GetInventory().GetCargo();		
					
					for ( int i = 0; i < CargoCount; i++ )
					{
						EntityAI CargoItem = CargoItems1.GetItem(i); 
						Object CargoObject = CargoItem;

						if ( m_MissionObjects.Find( CargoObject ) > -1 ) 
						{
							if ( CargoObject.GetType() == "TetracyclineAntibiotics")	FoundMedObjects++; 
							if ( FoodTypes.Find( CargoObject.GetType() ) > -1 )			FoundFoodObjects++;
						}
						else continue;					
						
						//When requested amount of supplies is present, despawn MissionObject & spawn rewards
						if ( FoundFoodObjects >= ReqFoodAmount && FoundMedObjects >= ReqMedAmount )
						{
							Print("[SMM] Player with SteamID64: "+ player.GetIdentity().GetPlainId() +" has successfully stored the requested amount of "+ (ReqFoodAmount + ReqMedAmount) +" MissionObjects in the container.");
							//delete container first
							GetGame().ObjectDelete( MissionObject );
							//call rewards spawn one second later 
							GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( this.SpawnRewards, 1000 );
							m_RewardsSpawned = true;
							m_MsgNum = -1;
							m_MsgChkTime = m_MissionTime + MsgDlyFinish;
							break;
						} 
					}
					LastCount = CargoCount;
				}
			} 
		}				
	}
		
	void UpdateBots( float dt )
	{
		//No bots involved in this mission		
	}
	
	bool DeployMission()
	{	//When first player enters the mission zone (primary/secondary)
		//Get MissionBuilding at secondary mission position
		if ( !m_MissionExtended )
		{			
			GetGame().GetObjectsAtPosition( m_MissionPosition , 1.0 , m_ObjectList , m_ObjectCargoList );
			for ( int i=0; i < m_ObjectList.Count(); i++ )
			{ 
				Object FoundObject = m_ObjectList.Get(i);
				if ( FoundObject.GetType() == "Land_Village_PoliceStation")
				{			 
					MissionBuilding = FoundObject;
					Print("[SMM] MissionBuilding extended is "+ m_MissionDescription[3] +" Police Station @ "+ m_MissionPosition );
					
					//new MissionPosition is rewards spawnpoint
					m_MissionPosition = MissionBuilding.ModelToWorld( RewardsPosition );
					break;
				}	
			}
		}
		
		if ( MissionBuilding )
		{
			//Call spawners	
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Call( this.SpawnObjects );
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Call( this.SpawnAIs );
			return true;		
		}
		else 
		{
			Print("[SMM] ERROR : MissionBuilding can't be found!");
			if ( MissionSettings.DebugMode ) Print("[SMM] MissionBuilding is NULL!");
			return false;
		}
	}
}

