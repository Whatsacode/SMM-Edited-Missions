class HeliStealMission extends SurvivorMissions
{
	//Mission related entities 
	Car Heli;
	ItemBase MissionObject;
	
	//Mission parameters
	int MsgDlyFinish = 30;					//seconds, message delay time after player has finished mission
	
	//Mission containers
	ref array<vector> ContainerSpawns = new array<vector>;
	ref array<vector> InfectedSpawns = new array<vector>;
	ref array<vector> FireSpawns = new array<vector>;
	ref array<string> InfectedTypes = new array<string>;
	ref array<string> HeliTypes = new array<string>;
	ref array<string> ammoTypes = new array<string>;
	ref array<string> foodTypes = new array<string>;	
	ref array<string> missionbots = new array<string>;
	ref array<string> helperbot = new array<string>;
	ref array<vector> patrol_100 = {"-44 0 -44","-44 0 0","-44 0 44","0 0 44","44 0 34","44 0 0","44 0 -44","0 0 -44"};
	eAIGroup m_activeGroup = null;

	//Mission variables 
	string SurvivorName;		
	
	bool IsExtended() return false;
	
	void HeliStealMission()
	{
		//Mission mission timeout
		m_MissionTimeout = 240;			//seconds, mission duration time
		
		//Mission zones
		m_MissionZoneOuterRadius = 500.0;	//meters (!Do not set lower than 200m), mission activation distance
		m_MissionZoneInnerRadius = 8.0;		//meters (!Do not set outside of 1-5m), mission finishing distance to target object
				
		//Mission informant
		m_MissionInformant = "The Information Broker";
	
		//Mission person names
		SurvivorName = "Gerry Lane";
		
		//Set mission messages
        m_MissionMessage1 = "Be advised: A helicopter has landed "+ m_MissionLocationDir +" of "+ m_MissionLocation + " and is offloading cargo.";
        m_MissionMessage2 = "Take out the guards, secure the heli, and exfil.";
        m_MissionMessage3 = "If it is locked, search the pilot for the key.";		
		
		//Container spawnpoints
		ContainerSpawns.Insert("2 1 1");
		ContainerSpawns.Insert("3 1 2");
		
		//Heli Spawnpoints spawnpoints
		HeliTypes.Insert("ExpansionMh6");
		HeliTypes.Insert("ExpansionMh6_Blueline");
		HeliTypes.Insert("ExpansionMh6_Digital");
		HeliTypes.Insert("ExpansionMh6_GrayWatcher");		
		
		//Create Random Ammo selection
		ammoTypes.Insert("AmmoBox_308WinTracer_20Rnd");
		ammoTypes.Insert("AmmoBox_308Win_20Rnd");
		ammoTypes.Insert("AmmoBox_545x39Tracer_20Rnd");
		ammoTypes.Insert("AmmoBox_545x39_20Rnd");	
		ammoTypes.Insert("AmmoBox_556x45Tracer_20Rnd");
		ammoTypes.Insert("AmmoBox_556x45_20Rnd");
		ammoTypes.Insert("AmmoBox_762x39Tracer_20Rnd");
		ammoTypes.Insert("AmmoBox_762x39_20Rnd");	
		ammoTypes.Insert("AmmoBox_762x54Tracer_20Rnd");
		ammoTypes.Insert("AmmoBox_762x54_20Rnd");	

		//Create Random Ammo selection
		foodTypes.Insert("BakedBeansCan");
		foodTypes.Insert("TacticalBaconCan");
		foodTypes.Insert("PeachesCan");
		foodTypes.Insert("SardinesCan");	
		foodTypes.Insert("SodaCan_Cola");
		foodTypes.Insert("SodaCan_Kvass");
		foodTypes.Insert("SodaCan_Pipsi");		
		
		//Infected spawnpoints
		InfectedSpawns.Insert("-10.5186 0 25.0269");
		InfectedSpawns.Insert("24.9775 0 -10.4146");
		InfectedSpawns.Insert("-30.1726 0 -6.2729");
		InfectedSpawns.Insert("-20.9209 0 4.6636");
		InfectedSpawns.Insert("15.0283 0 -10.3276");
		InfectedSpawns.Insert("7.2461 0 30.5884");
		InfectedSpawns.Insert("-20.6855 0 5.9956");
		InfectedSpawns.Insert("40 0 20");
		InfectedSpawns.Insert("-20 0 -40");
		InfectedSpawns.Insert("-50 0 50");
		InfectedSpawns.Insert("35 0 40");
		InfectedSpawns.Insert("-40 0 -20");
		InfectedSpawns.Insert("-30 0 -40");
		
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
	}
	
	void ~HeliStealMission()
	{
		//Despawn all remaining mission objects
		if ( m_MissionObjects )
		{	
			Print("[SMM] Despawning "+ m_MissionObjects.Count() +" mission objects from old mission...");				
			for ( int i = 0; i < m_MissionObjects.Count(); i++ )
			{
				if ( !m_MissionObjects.Get(i) ) continue;
				else GetGame().ObjectDelete( m_MissionObjects.Get(i) );		
			}
			m_MissionObjects.Clear();
		}
		
		//Despawn mission AI's
		#ifdef EAI
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
		#endif
		//Delete PlayersInZone list & reset container takeaway
		if ( m_PlayersInZone )	m_PlayersInZone.Clear();
		if ( m_ContainerWasTaken ) m_ContainerWasTaken = false;	
	}
	
	void SpawnObjects()
	{
		
		//Spawn crashed plane crashed C130 
		int PlaneOriConversion;
		string PlaneOrientation;
		
		PlaneOriConversion = m_MissionDescription[3].ToInt() - 180;
		if ( PlaneOriConversion < 0 ) PlaneOriConversion += 360;
		PlaneOrientation = PlaneOriConversion.ToString() +" 0 0";
		
		string RandomHeli = HeliTypes.GetRandomElement();
		string RandomAmmo1 = ammoTypes.GetRandomElement();
		string RandomAmmo2 = ammoTypes.GetRandomElement();
		string RandomAmmo3 = ammoTypes.GetRandomElement();
		string RandomAmmo4 = ammoTypes.GetRandomElement();
		string RandomAmmo5 = ammoTypes.GetRandomElement();
		string RandomAmmo6 = ammoTypes.GetRandomElement();
		string RandomAmmo7 = ammoTypes.GetRandomElement();
		string RandomAmmo8 = ammoTypes.GetRandomElement();
		string RandomFood1 = foodTypes.GetRandomElement();
		string RandomFood2 = foodTypes.GetRandomElement();
		string RandomFood3 = foodTypes.GetRandomElement();
		string RandomFood4 = foodTypes.GetRandomElement();
		string RandomFood5 = foodTypes.GetRandomElement();
		string RandomFood6 = foodTypes.GetRandomElement();
		string RandomFood7 = foodTypes.GetRandomElement();
		string RandomFood8 = foodTypes.GetRandomElement();
		
		Print("[DEBUG] *********TRYING METHOD ONE!!!!!********************");
		
		Heli = Car.Cast(GetGame().CreateObject( RandomHeli, m_MissionPosition ));
		Heli.SetOrientation( PlaneOrientation.ToVector() );
		Heli.PlaceOnSurface();
		Heli.GetInventory().CreateAttachment("ExpansionHelicopterBattery");
		Heli.GetInventory().CreateAttachment("ExpansionHydraulicHoses");
		Heli.GetInventory().CreateAttachment("ExpansionIgniterPlug");
		Heli.GetInventory().CreateInInventory("CanisterGasoline");
		Heli.GetInventory().CreateInInventory("CanisterGasoline");
		Heli.GetInventory().CreateInInventory("CanisterGasoline");
		Heli.GetInventory().CreateInInventory("CanisterGasoline");
		Heli.GetInventory().CreateInInventory("CanisterGasoline");
		Heli.GetInventory().CreateInInventory("CanisterGasoline");


		EntityAI.Cast( Heli ).SetLifetime( (m_MissionTimeout - m_MissionTime) + 30 );
		m_MissionObjects.Insert( Heli );

		//Spawn containers 
		int selectedLoadout;
		
		for (int i=0; i < ContainerSpawns.Count(); i++)
		{	
			MissionObject = ItemBase.Cast( GetGame().CreateObject( "WoodenCrate", Heli.ModelToWorld( ContainerSpawns.Get(i))));
			
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
				
			//Insert mission container into mission objects list
			m_MissionObjects.Insert( MissionObject );
		}
							
		Print("[SMM] Survivor Mission "+ m_selectedMission +" :: "+ m_MissionName +" ...mission deployed!");
	}
	
	#ifdef EAI
	void SpawnPatrol(vector pos, string loadout = "Army.json") 

	{
    	eAIGame game = MissionServer.Cast(GetGame().GetMission()).GetEAIGame();
    	eAIGroup MissionGroup = m_activeGroup;
		eAIBase ai = game.SpawnAI_Patrol(pos, loadout);
	
		//	m_MissionAIs.Insert(ai);
		m_activeGroup = ai.GetGroup();

		foreach (vector v : patrol_100) {m_activeGroup.AddWaypoint(v);}

		int count = 3; // temporary so we don't decrease the actual amount

		while (count > 1) 
		
		{
			(game.SpawnAI_Helper(ai, loadout)).RequestTransition("Rejoin");
			//m_MissionAIs.Insert(ai);
			count--;
		}
	}

	#endif
	void SpawnAIs()
	{	
		for (int u = 0; u < patrol_100.Count(); u++) 
		{
            vector pos = m_MissionPosition + patrol_100[u];
            float x = pos[0] + Math.RandomFloat(-12, 12);
            float z = pos[2] + Math.RandomFloat(-12, 12);
            float y = GetGame().SurfaceY(x, z);
            patrol_100[u] = Vector (x, y, z);
    	}
		vector gpos = { Math.RandomFloatInclusive(-10.0, -3.0), 0, Math.RandomFloatInclusive(-10.0, -3.0) };
			
			vector SoldierBotPos1 = Heli.ModelToWorld( gpos );

		SpawnPatrol(SoldierBotPos1);
	}
	#ifdef EAI
		
	#endif

	void ObjDespawn() 
	{	
	
		//Despawn all mission objects at mission timeout except those retains until next mission
		for ( int i = 0; i < m_MissionObjects.Count(); i++ )
		{
			if ( m_MissionObjects.Get(i))
			{
				//Delete Object
				GetGame().ObjectDelete( m_MissionObjects.Get(i) );
			}		
		}
		
	}
	
	void MissionFinal()
	{	
		EntityAI.Cast( Heli ).SetLifetime( 3888000 );

		m_MissionObjects.Remove(0);
		m_RewardsSpawned = true;
		m_MsgNum = -1;
		m_MsgChkTime = m_MissionTime + MsgDlyFinish;
		//Spawn infected pilot
		vector InfectedPos = Heli.ModelToWorld( "-9 0 9" );
		m_MissionAIs.Insert( GetGame().CreateObject( "ZmbM_CommercialPilotOld_Olive" , InfectedPos , false , true ) );
		DayZInfected InfectedSurvivor = DayZInfected.Cast( m_MissionAIs[0] );
			InfectedSurvivor.GetInventory().CreateAttachment("ZSh3PilotHelmet_Green");
			InfectedSurvivor.GetInventory().CreateAttachment("UKAssVest_Olive");
			InfectedSurvivor.GetInventory().CreateInInventory("ExpansionCarKey");
			
	}
	
	void PlayerChecks( PlayerBase player )
	{
		//nothing to check
	}
		
	void UpdateBots(float dt)
	{
		//no bots involved in this mission		
	}
	
	bool DeployMission()
	{	//When first player enters the mission zone (primary/secondary)
		if ( m_MissionPosition && m_MissionPosition != "0 0 0" )
		{
			//Call spawners	
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Call( this.SpawnObjects );
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Call( this.SpawnAIs );
			return true;		
		}
		else 
		{
			Print("[SMM] ERROR : Mission position was rejected or doesn't exist. MissionPosition is NULL!");
			return false;
		}
	}
}

