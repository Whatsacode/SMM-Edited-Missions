class ApartmentSideMission extends SideMissions
{
	//Mission related entities 
	Object MissionBuilding;

	//Mission parameters	
	int MsgDlyFinish = 300;					//seconds, message delay time after player has finished mission
	
	//Mission containers
	ref array<vector> Spawnpoints = new array<vector>;
	ref array<ref Param3<string,vector,vector>> Barricades = new array<ref Param3<string,vector,vector>>;
	ref array<vector> InfectedSpawns = new array<vector>;
	ref array<string> InfectedTypes = new array<string>;
	
	//Mission variables 
	string SurvivorName;	
	
	bool IsExtended() return false;
	
	void ApartmentSideMission()
	{
		//Mission timeout
		m_MissionTimeout = 2700;			//seconds, mission duration time
		
		//Mission zone params
		m_MissionZoneOuterRadius = 90.0;	//meters (!Do not set lower than 50m), mission activation distance
		m_MissionZoneInnerRadius = 2.0;		//meters (!Do not set outside of 1-5m), mission finishing distance to target object
				
		//Mission informant
		m_MissionInformant = "Dr. Legasov";
		
		//Mission person names
		TStringArray SurvivorNames = {"Yuri", "Michail", "Boris", "Valeri", "Anatoli", "Ivan", "Alexej", "Dimitrij", "Sergej", "Nikolai" };
		SurvivorName = SurvivorNames.GetRandomElement();
						
		//Mission messages 
        m_MissionMessage1 = SurvivorName +" was one of my best students. I used to talk to him on the radio, but now I have lost contact with him.";
        m_MissionMessage2 = "He told me that he has hidden a seachest with good equipment somewhere in the apartments. A few days ago he barricaded the whole building against the infected.";
        m_MissionMessage3 = "He used to live in one of the apartments\n** "+ m_MissionLocationDir +" of "+ m_MissionLocation+" **\nPlease check if "+SurvivorName+" is still alive. If not, then take his stuff to help you survive.";
				
		//Mission object spawnpoints in mission building	
		Spawnpoints.Insert("8.1257 2.7203 3.1963");
		Spawnpoints.Insert("-8.3906 -0.6797 -1.1826");
		Spawnpoints.Insert("-7.3033 6.1203 -5.8271");
		Spawnpoints.Insert("-3.6415 6.1202 5.5020");
		Spawnpoints.Insert("-4.4313 -4.0797 -1.4932");
		Spawnpoints.Insert("3.4453 -6.3297 -2.0181");
		Spawnpoints.Insert("3.2646 2.7203 -1.6377");
		Spawnpoints.Insert("7.1572 2.7203 -6.0815");
		Spawnpoints.Insert("2.8496 2.7203 -6.1870");
		Spawnpoints.Insert("2.9014 2.7202 4.9683");
		Spawnpoints.Insert("-10.0996 6.1202 5.7339");
		
		//Infected spawnpoints in mission building
		InfectedSpawns.Insert("-1.5186 -7.4796 1.0269");
		InfectedSpawns.Insert("4.9775 -7.4796 -1.4146");
		InfectedSpawns.Insert("-7.1726 -4.0797 -6.2729");
		InfectedSpawns.Insert("-2.9209 -0.6797 4.6636");
		InfectedSpawns.Insert("5.0283 2.7203 -1.3276");
		InfectedSpawns.Insert("-7.2461 6.1203 -1.5884");
		InfectedSpawns.Insert("-1.6855 6.1204 5.9956");
		
		//Infected types
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
		
		//Entrance barricade  (view from inside building!)
		//Log frame
		Barricades.Insert( new Param3<string,vector,vector>("WoodenLog", "-0.300 -6.740 6.940", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenLog", "-0.300 -5.200 6.768", "0 -90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenLog", "-0.300 -7.050 6.376", "0 45 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-0.300 -7.495 6.325", "-90 0 0"));
		//Planks on ground
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "0.660 -7.495 6.000", "-50 0 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-0.660 -7.495 6.000", "-100 0 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-1.260 -7.495 5.700", "-130 0 0"));	
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-1.560 -7.450 5.900", "-230 0 0"));		
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "0.390 -7.460 6.100", "-35 -5 -2"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-0.990 -7.460 6.100", "-85 -5 -2"));		
		//oustside
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-0.660 -8.115 7.800", "30 -45 -20"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "0.360 -8.015 7.730", "120 17 -40"));
		//right plank wall
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "0.360 -7.410 6.860", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "0.360 -7.207 6.860", "0 -90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "0.360 -7.004 6.860", "180 -90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "0.360 -6.831 6.705", "0 100 23"));		
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "0.360 -5.583 6.850", "180 96 -2"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "0.360 -5.377 6.860", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "0.360 -5.165 6.860", "180 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "0.360 -4.955 6.860", "0 -90 0"));
		//left plank wall
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-0.920 -5.377 6.860", "0 -90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-0.920 -5.165 6.860", "180 -90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-0.920 -4.955 6.860", "0 90 0"));			
	}
	
	void ~ApartmentSideMission()
	{		
		//Despawn remaining mission objects
		if ( m_MissionObjects )
		{
			Print("[SMM] Despawning "+ m_MissionObjects.Count() +" mission objects from old mission...");
			for (int i=0; i < m_MissionObjects.Count(); i++ )
			{
				if ( !m_MissionObjects.Get(i))	continue;
				else GetGame().ObjectDelete( m_MissionObjects.Get(i));
			}
			m_MissionObjects.Clear();
		}
		
		//Despawn mission AI's
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
		
	void SpawnObjects()
	{	
		//Spawn seachest as mission object
		ItemBase MissionObject = ItemBase.Cast( GetGame().CreateObject( "SeaChest", m_MissionPosition, false, false, false ) );
		
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
					
		//Insert mission crate into mission objects list
		m_MissionObjects.Insert( MissionObject );
		
		//Spawn barricades		
		for ( int i=0; i < Barricades.Count(); i++ )
		{
			Param3<string,vector,vector> BarricadeDef = Barricades.Get(i);
			string BarricadeType = BarricadeDef.param1;
			vector BarricadePos = MissionBuilding.ModelToWorld( BarricadeDef.param2 );
			vector BarricadeOri = BarricadeDef.param3;
			vector BarricadeDir = MissionBuilding.GetDirection();
			
			Object PlankBarricade = GetGame().CreateObject( BarricadeType, BarricadePos, false, false, true );
			PlankBarricade.SetPosition( BarricadePos );
			PlankBarricade.SetDirection( BarricadeDir );
			PlankBarricade.SetOrientation( PlankBarricade.GetOrientation() + BarricadeOri );
			ItemBase.Cast( PlankBarricade ).SetQuantity(1);
			ItemBase.Cast( PlankBarricade ).SetTakeable( false );
			m_MissionObjects.Insert( PlankBarricade );
		}
		
		Object phObject = GetGame().CreateObject("Land_Boat_Small1", MissionBuilding.ModelToWorld("0.360 -7.410 6.730"), true );
		phObject.SetPosition( MissionBuilding.ModelToWorld("1.560 -7.340 6.730"));
		phObject.SetDirection( MissionBuilding.GetDirection() );
		phObject.SetOrientation( phObject.GetOrientation() + "0 90 0");
		m_MissionObjects.Insert( phObject );
	
		Print("[SMM] Survivor Mission "+ m_selectedMission +" :: "+ m_MissionName +" ...mission deployed!");
	}	
	
	void SpawnAIs()
	{			
		//Spawn survivor 
		vector SurvivorPos = MissionBuilding.ModelToWorld("-6.3545 6.1203 -4.6489");
		
		PlayerBase DeadSurvivor = PlayerBase.Cast(GetGame().CreatePlayer( null, "SurvivorM_Oliver", SurvivorPos, 0 , "Oliver"));
        	DeadSurvivor.GetInventory().CreateInInventory("HikingJacket_Black");
        	DeadSurvivor.GetInventory().CreateInInventory("Jeans_Blue");
        	DeadSurvivor.GetInventory().CreateInInventory("HikingBoots_Brown");
			DeadSurvivor.GetInventory().CreateInInventory("Glock19");
			DeadSurvivor.GetInventory().CreateInInventory("Mag_Glock_15Rnd");
        DeadSurvivor.SetHealth("","",20);
		DeadSurvivor.SetName( SurvivorName );
		DeadSurvivor.SetBloodyHands(true);
		DeadSurvivor.SetPosition( SurvivorPos );
		DeadSurvivor.SetSynchDirty();
		m_MissionAIs.Insert( DeadSurvivor );			
				
		
		//Spawn infected girl
		vector InfGirlPos = MissionBuilding.ModelToWorld("-9.4111 6.1203 -4.8696");
		m_MissionAIs.InsertAt( GetGame().CreateObject( "ZmbF_JournalistNormal_White", InfGirlPos, false, true ), 1 );
		DayZInfected InfectedGirl = DayZInfected.Cast( m_MissionAIs[1] ); 
		InfectedGirl.GetInventory().CreateAttachment("PressVest_Blue");
		DayZInfectedCommandMove moveCommand = InfectedGirl.GetCommand_Move();
		moveCommand.SetIdleState(2); 
		
		//Spawn infected  
		for ( int j = 0 ; j < InfectedSpawns.Count() ; j++ )
		{
		  	string RandomInfected = InfectedTypes.GetRandomElement();
			vector InfectedPos = MissionBuilding.ModelToWorld( InfectedSpawns.Get(j) );
			DayZInfected Zed = DayZInfected.Cast( GetGame().CreateObject( RandomInfected, InfectedPos, false, true ));
			//DayZInfectedCommandMove moveCommandZ = Zed.GetCommand_Move();	moveCommandZ.SetIdleState(2);	//Set infected mind state alarmed
			m_MissionAIs.Insert( Zed );
		}
			
	}
			
	void ObjDespawn() 
	{
		//Despawn all mission objects at mission timeout except those retains until next mission
		for (int i = 0; i < m_MissionObjects.Count(); i++ )
		{
			if ( m_MissionObjects.Get(i))
			{
				//Exception: Barricades will remain
				if ( m_MissionObjects.Get(i).GetType() == "WoodenLog" ) continue;
				if ( m_MissionObjects.Get(i).GetType() == "WoodenPlank" ) continue;
				if ( m_MissionObjects.Get(i).GetType() == "Land_Boat_Small1" ) continue;

				//Delete Object
				GetGame().ObjectDelete( m_MissionObjects.Get(i));
			}
		}
	}
	
	void MissionFinal()
	{	//When player enters last mission target zone
		//Open all doors of mission building
		Building Tenement = Building.Cast( MissionBuilding );
		for ( int i=0; i < 32; i++ ) if ( !Tenement.IsDoorOpen(i) ) Tenement.OpenDoor(i);
		GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( GetGame().UpdatePathgraphRegionByObject, 1000, false, Tenement );
		
		//Respawn some infected 
		for ( int j = 0 ; j < InfectedSpawns.Count() ; j++ )
		{
    	   	string RandomInfected = InfectedTypes.GetRandomElement();
			vector InfectedPos = MissionBuilding.ModelToWorld( InfectedSpawns.Get(j));
			float InfectedDistance = vector.Distance( InfectedPos, m_MissionPosition );
			if ( InfectedDistance > 5.0 )
			{
				DayZInfected Zed = DayZInfected.Cast( GetGame().CreateObject( RandomInfected, InfectedPos, false, true ));
				DayZInfectedCommandMove moveCommandZ = Zed.GetCommand_Move();	moveCommandZ.SetIdleState(2);
				m_MissionAIs.Insert( Zed );
			}		
		}
		
		//Finish mission
		m_RewardsSpawned = true;
		m_MsgNum = -1;
		m_MsgChkTime = m_MissionTime + MsgDlyFinish;
	}
	
	void PlayerChecks( PlayerBase player )
	{
		//Check if container gets taken from player
		if ( MissionSettings.Opt_DenyObjTakeaway )
		{
			if ( m_MissionObjects[0] && m_MissionObjects[0].ClassName() == "SeaChest" )
			{
				if ( player.GetInventory().HasEntityInInventory( EntityAI.Cast( m_MissionObjects[0] )) && !m_ContainerWasTaken )
				{
					m_ContainerWasTaken = true;
					Print("[SMM] Mission object container was taken by a player ...and will be deleted.");
					GetGame().ObjectDelete( m_MissionObjects[0] );
				}
			}
		}		
	}
		
	void UpdateBots(float dt)
	{
		//No bots involved in this mission		
	}
			
	bool DeployMission()
	{	//When first player enters the mission zone (primary/secondary)
		//Search for mission building at mission position	
		GetGame().GetObjectsAtPosition( m_MissionPosition , 1.0 , m_ObjectList , m_ObjectCargoList );
		for ( int i = 0 ; i < m_ObjectList.Count(); i++ )
		{ 
			Object FoundObject = m_ObjectList.Get(i);
			if ( FoundObject.GetType() == "Land_Tenement_Small" )
			{	
				MissionBuilding = FoundObject; 				
				Print("[SMM] MissionBuilding is "+ MissionBuilding.GetType() +" at "+ m_MissionDescription[2] +" of "+ m_MissionDescription[1] +" @ "+ MissionBuilding.GetPosition() );
				
				//new MissionPosition is rewards spawnpoint
				m_MissionPosition = MissionBuilding.ModelToWorld( Spawnpoints.GetRandomElement() );
				break;
			}	 
		}	
				
		if ( MissionBuilding )
		{	
			//Close all doors of mission building
			Building Tenement = Building.Cast( MissionBuilding );
			for (int k=0; k < 32; k++ )
			{
				if ( Tenement.IsDoorOpen(k) ) Tenement.CloseDoor(k);
			}
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( GetGame().UpdatePathgraphRegionByObject, 1000, false, Tenement );
			
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