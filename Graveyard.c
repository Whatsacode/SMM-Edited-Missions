class GraveyardMission extends SurvivorMissions
{
	//Mission related entities 
	ItemBase MissionObject;
	UndergroundStash stash;
	
	//Mission parameters
	int MsgDlyFinish = 300;					//seconds, message delay time after player has finished mission
	
	//Mission containers
	ref array<vector> InfectedSpawns = new array<vector>;
	ref array<string> InfectedTypes = new array<string>;

	//Mission variables 
	string SurvivorName;		
	
	bool IsExtended() return false;
	
	void GraveyardMission()
	{
		//Mission mission timeout
		m_MissionTimeout = 2700;			//seconds, mission duration time
		
		//Mission zones
		m_MissionZoneOuterRadius = 100.0;	//meters (!Do not set lower than 200m), mission activation distance
		m_MissionZoneInnerRadius = 2.0;		//meters (!Do not set outside of 1-5m), mission finishing distance to target object
				
		//Mission informant
		m_MissionInformant = "Dr. Legasov";
	
		//Mission person names
		TStringArray SurvivorNames = {"Shukov", "Stonov", "Alexejev", "Kasakov", "Stepanov", "Ivanov", "Mironov", "Dimitrijev", "Antonov", "Sorokin"};
		SurvivorName = SurvivorNames.GetRandomElement();
		
		//Set mission messages
		m_MissionMessage1 = "I just received that the commander of the Chernarus Defense Troups General Major "+ SurvivorName +" hasn't survived his infection.";
		m_MissionMessage2 = "He was one of the Soviet Army officers in Chernarus. "+ SurvivorName +" told me that he lost over 2000 men here and will never give up the fight against the infection as long as he lives. He got infected while securing residents of "+ m_MissionLocation +".";
		m_MissionMessage3 = "He hided some equipment at the graveyard of\n** "+ m_MissionLocation +", "+ m_MissionLocationDir +" near the church **\nI think someone should get his lagcy. He burried it anywhere near the graves. You need atleast a shovel. Take care!";
		
		//Infected spawnpoints
		InfectedSpawns.Insert("-10.5186 0 25.0269");
		InfectedSpawns.Insert("24.9775 0 -10.4146");
		InfectedSpawns.Insert("-30.1726 0 -6.2729");
		InfectedSpawns.Insert("-20.9209 0 4.6636");
		InfectedSpawns.Insert("15.0283 0 -10.3276");
		InfectedSpawns.Insert("7.2461 0 30.5884");
		InfectedSpawns.Insert("-20.6855 0 5.9956");
		
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
	
	void ~GraveyardMission()
	{
		//Despawn all remaining mission objects
		if ( m_MissionObjects )
		{	
			Print("[SMM] Despawning "+ m_MissionObjects.Count() +" mission objects from old mission...");				
			for ( int i = 0; i < m_MissionObjects.Count(); i++ )
			{
				if ( !m_MissionObjects.Get(i) ) continue;
				else 
				{
					//Delete Object clientside first
					if ( m_MissionObjects.Get(i).GetType() == "ClutterCutter2x2" )
					GetGame().RemoteObjectDelete( m_MissionObjects.Get(i) );
					
					//Delete Object serverside	
					GetGame().ObjectDelete( m_MissionObjects.Get(i) );		
				}
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
		
		//Create underground stash  
		stash = UndergroundStash.Cast( GetGame().CreateObject( "UndergroundStash", m_MissionPosition ));
		stash.PlaceOnGround(); 
		Print(" Orientation UndergroundStash : "+ stash.GetOrientation().ToString() );
		vector pos = stash.GetPosition();
		vector ori = stash.GetOrientation();
		
		if ( ori[2] == -180 || ori[2] == 180 )
		{	//Bugfix for invisible Undergroundstashes
			ori[2] = 0;
			stash.SetOrientation( ori );
		}
				
		//Spawn seachest in stash
		MissionObject = ItemBase.Cast( stash.GetInventory().CreateInInventory("SeaChest"));		
		
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

		//Clutter cutter stash 	
		Object cc_stash = GetGame().CreateObject( "ClutterCutter2x2" , MissionObject.GetPosition() );
		GetGame().RemoteObjectCreate( cc_stash );		
		
		//Insert mission objects into mission objects list
		m_MissionObjects.Insert( MissionObject );
		m_MissionObjects.Insert( stash );		 
		m_MissionObjects.Insert( cc_stash );			
		
		Print("[SMM] Mission rewards spawned in reward container. Randomly selected rewards were added plus "+ selectedLoadout +"." );					
	}
	
	void SpawnAIs()
	{
		//Spawn infected
		for ( int j = 0 ; j < InfectedSpawns.Count() ; j++ )
		{
    	   	string RandomInfected = InfectedTypes.GetRandomElement();
			vector InfectedPos = MissionObject.ModelToWorld( InfectedSpawns.Get(j) );
			m_MissionAIs.Insert( GetGame().CreateObject( RandomInfected, InfectedPos, false, true ) );
		}		
	}

	void ObjDespawn() 
	{	
		//Despawn nothing
	}
				
	void MissionFinal()
	{	//When player enters last mission target zone
		//Respawn some infected 
		for ( int j = 0 ; j < 3 ; j++ )
		{
    	   	string RandomInfected = InfectedTypes.GetRandomElement();
			vector InfectedPos = MissionObject.ModelToWorld( InfectedSpawns.Get(j) );
			m_MissionAIs.Insert( GetGame().CreateObject( RandomInfected, InfectedPos, false, true ) );			
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
			Print("[SMM] Mission position was rejected or doesn't exist!");
			return false;
		}					
	}	
}