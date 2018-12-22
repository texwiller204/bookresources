--=======================================
-- Game Development With Lua
-- by Paul Schuytema and Mark Manyen
-- (c) copyright 2005, Charles River Media
-- All Rights Reserved.  U.S.A.
--=======================================
-- filename:  GUI_DamageFire.lua
-- author:    Nick Carlson
-- created:   March 10, 2005
-- descrip:   AI reacts to damage
--=======================================

-- first steps


--dofile calls for sub-GUIs


--100s Sprites


--200s Text items
--Script name
CreateItem(GUI_INGAME + 201,"TextField")
SetItemPosition(GUI_INGAME + 201, 26, 26, 0, 0)
SetFont(GUI_INGAME + 201, "Arial", 18)
ItemCommand(GUI_INGAME + 201, "SetColor", 255,255,255,255)
ItemCommand(GUI_INGAME + 201, "SetString", gScenarioScript)

--Enemy damage count
CreateItem(GUI_INGAME + 202,"TextField")
SetItemPosition(GUI_INGAME + 202, 26, 60, 0, 0)
SetFont(GUI_INGAME + 202, "Arial", 18)
ItemCommand(GUI_INGAME + 202, "SetColor", 255,255,255,255)
ItemCommand(GUI_INGAME + 202, "SetString", "Enemy Damage: 00%")


--300s Buttons


--400s Check Boxes and Radio buttons


--500s List objects


--600s Special objects (bar, chart, sprite ring, etc.)


--functions related to this GUI (not used anywhere else)
--=======================================
-- function:  DamageFireSetUp()
-- author:    Nick Carlson
-- created:   February 11, 2005
-- returns:   nothing (process)
-- descrip:   sets constants for the game
--=======================================
function DamageFireSetUp()
    --Initial player constants
    myRotation = 1 --Player's rotation (#)
    myX = math.random(20,760)        --Player's x coordinate (#)
    myY = math.random(20,560)        --Player's y coordinate (#)
    myXThrust = 0  --Player's thrust along the x-axis (#)
    myYThrust = 0  --Player's thrust along the y-axis (#)
    alive = "yes"  --Player's life status ("yes" or "no")

    turRotation = 1 --Turret's rotation (#)
    turX = 390      --Turret's x coordinate (#)
    turY = 290      --Turret's y coordinate (#)

    --Initial limits
    respawnInterval = 15  --Number respawnCounter must reach to respawn player (#)

    --Initial setting of counters
    respawnCounter = 0    --Player's death period (#)
    timeCounter = 0       --Passage of time (#)
    turFireCounter = 0    --Turret's fire interval (#)

    --Preferred game speed
    refreshRate = .1 --Seconds between timer expirations (#)
end


--=======================================
-- function:  DamageFireEnemyInit()
-- author:    Nick Carlson
-- created:   March 3, 2005
-- returns:   nothing (process)
-- descrip:   sets up initial enemies
--=======================================
function DamageFireEnemyInit()

    enemyCount = 1 --Number of enemies in the game
    myEnemies = {} --Creates myEnemies table

    --Creates table, one entry per potential enemy
    for indx = 1,enemyCount do
        --Creates a table to hold the data for each enemy
        myEnemies[indx] = {}
        --Initial values
        myEnemies[indx].EX = math.random(20,760)
        myEnemies[indx].EY = math.random(20,560)
        myEnemies[indx].XTHRUST = 0 --Thrust along the x-axis (#)
        myEnemies[indx].YTHRUST = 0 --Thrust along the y-axis (#)
        myEnemies[indx].ROT = math.random(1,8) --Rotation of enemy ship (#)
        myEnemies[indx].ID = GUI_RUNTIME_SPRITES + indx + 100 --Starts GUI identification at 101 (#)
        myEnemies[indx].REACT = 1 --Reaction time interval (#)
        myEnemies[indx].MAX = 7 --Maximum thrust (#)
        myEnemies[indx].TYPE = 1 --AI type (1)
        myEnemies[indx].DAMAGE = 0 --Damage counter (#)
        print("Now in Normal Mode")
        CreateItem(myEnemies[indx].ID, "Sprite", "e1_ship1.bmp")
        SetItemPosition(myEnemies[indx].ID, myEnemies[indx].EX, myEnemies[indx].EY, 20, 20)
    end
end


--=======================================
-- function:  DamageFireDrawEnemyShip()
-- author:    Nick Carlson
-- created:   February 11, 2005
-- returns:   nothing (process)
-- descrip:   refreshes the image of the enemy ship
--=======================================
function DamageFireDrawEnemyShip()

    for indx = 1,enemyCount do
        if myEnemies[indx].ID ~= nil then
            DeleteItem(myEnemies[indx].ID)
            --Determine enemy's new thrust
            newThrust = math.random(0,2)
            if myEnemies[indx].ROT == 1 then --Up
                myEnemies[indx].YTHRUST = myEnemies[indx].YTHRUST - newThrust
            end
            if myEnemies[indx].ROT == 2 then --Up/right
                myEnemies[indx].YTHRUST = myEnemies[indx].YTHRUST - newThrust
                myEnemies[indx].XTHRUST = myEnemies[indx].XTHRUST + newThrust
            end
            if myEnemies[indx].ROT == 3 then --Right
                myEnemies[indx].XTHRUST = myEnemies[indx].XTHRUST + newThrust
            end
            if myEnemies[indx].ROT == 4 then --Down/right
                myEnemies[indx].YTHRUST = myEnemies[indx].YTHRUST + newThrust
                myEnemies[indx].XTHRUST = myEnemies[indx].XTHRUST + newThrust
            end
            if myEnemies[indx].ROT == 5 then --Down
                myEnemies[indx].YTHRUST = myEnemies[indx].YTHRUST + newThrust
            end
            if myEnemies[indx].ROT == 6 then --Down/left
                myEnemies[indx].YTHRUST = myEnemies[indx].YTHRUST + newThrust
                myEnemies[indx].XTHRUST = myEnemies[indx].XTHRUST - newThrust
            end
            if myEnemies[indx].ROT == 7 then --Left
                myEnemies[indx].XTHRUST = myEnemies[indx].XTHRUST - newThrust
            end
            if myEnemies[indx].ROT == 8 then --Up/left
                myEnemies[indx].YTHRUST = myEnemies[indx].YTHRUST - newThrust
                myEnemies[indx].XTHRUST = myEnemies[indx].XTHRUST - newThrust
            end
            --Check new thrust against enemy's maximum thrust
            if myEnemies[indx].YTHRUST > myEnemies[indx].MAX then
                myEnemies[indx].YTHRUST = myEnemies[indx].MAX
            end
            if myEnemies[indx].YTHRUST < (-1 * myEnemies[indx].MAX) then
                myEnemies[indx].YTHRUST = -1 * myEnemies[indx].MAX
            end
            if myEnemies[indx].XTHRUST > myEnemies[indx].MAX then
                myEnemies[indx].XTHRUST = myEnemies[indx].MAX
            end
            if myEnemies[indx].XTHRUST < (-1 * myEnemies[indx].MAX) then
                myEnemies[indx].XTHRUST = -1 * myEnemies[indx].MAX
            end
            --Checks for collisions and displays the new enemy ship
            shipName = string.format("%s%d%s%d%s", "e", myEnemies[indx].TYPE, "_ship", myEnemies[indx].ROT, ".bmp")
            myEnemies[indx].EX = myEnemies[indx].EX + myEnemies[indx].XTHRUST
            myEnemies[indx].EY = myEnemies[indx].EY + myEnemies[indx].YTHRUST
            CollisionCheck(indx, myEnemies[indx].EX, myEnemies[indx].EY)
            CreateItem(myEnemies[indx].ID, "Sprite", shipName)
            SetItemPosition(myEnemies[indx].ID, myEnemies[indx].EX, myEnemies[indx].EY, 20, 20)
            DamageFireWallCheck("enemy", indx, myEnemies[indx].EX, myEnemies[indx].EY)
        end
    end
end


--=======================================
-- function:  DamageFireEnemyFacing(indx)
-- author:    Nick Carlson
-- created:   February 11, 2005
-- returns:   nothing (process)
-- descrip:   calculates the actions of a specific ship's AI
--=======================================
function DamageFireEnemyFacing(indx)
--indx is the myEnemies table index assigned to the enemy

    --Determine distance from projectiles
    projectileDistance = 100
    tX = myX + 10
    tY = myY + 10
    state = "none"

    if (myEnemies[indx].DAMAGE >= 3) and (myEnemies[indx].DAMAGE < 6) then
        print("Now in Avoidance Mode")
        for i = 1, pCount do
            if myProjectiles[i].PROJ_ID ~= nil then --Projectile exists
                --Determine distance from closest target
                tempProjectileDistance = math.sqrt(((myEnemies[indx].EX + 10) - (myProjectiles[i].PROJ_X + 2))^2 + ((myEnemies[indx].EY + 10) - (myProjectiles[i].PROJ_Y + 2))^2)
                if tempProjectileDistance < projectileDistance then
                    projectileDistance = tempProjectileDistance
                    tX = myProjectiles[i].PROJ_X + 2
                    tY = myProjectiles[i].PROJ_Y + 2
                    state = "avoid"
                end
            end
        end
    elseif (myEnemies[indx].DAMAGE >= 6) then
        tX = 100
        tY = 300
        state = "protection"
        print("Now in Protection Mode")
    end
    DamageFireSetTravelDirection(indx, state, tX, tY)
end


--=======================================
-- function:  DamageFireSetTravelDirection(indx, state, tX, tY)
-- author:    Paul Schuytema
-- created:   February 1, 2004
-- returns:   nothing (process)
-- descrip:   sets the enemy's rotation based upon the coordinates of its goal
--=======================================
function DamageFireSetTravelDirection(indx, state, tX, tY)
--indx is the myEnemies table index assigned to the enemy or "turret"
--state is the tracking method of the AI ("avoid", "protection", or "none")
--tX is the X coordinate of the goal (target or player's ship)
--tY is the Y coordinate of the goal (target or player's ship)

    local X
    local Y
    local Rot

    if indx == "turret" then
        X = turX + 10
        Y = turY + 10
        Rot = turRotation
    else
        X = myEnemies[indx].EX + 10
        Y = myEnemies[indx].EY + 10
        Rot = myEnemies[indx].ROT
    end

    if tX < X then
        if tY < Y then
            if (Y - tY) > 150 then
                if (X - tX) > 150 then
                    Rot = 8 --Up/left
                else
                    Rot = 1 --Up
                end
            elseif (Y - tY) > 30 then
                Rot = 8 --Up/left
            else
                Rot = 7 --Left
            end
        elseif tY == Y then
            Rot = 7 --Left
        elseif tY > Y then
            if (tY - Y) > 150 then
                if (X - tX) > 150 then
                    Rot = 6 --Down/left
                else
                    Rot = 5 --Down
                end
            elseif (tY - Y) > 30 then
                Rot = 6 --Down/left
            else
                Rot = 7 --Left
            end
        end
    elseif tX == X then
        if tY <= Y then
            Rot = 1 --Up
        else
            Rot = 5 --Down
        end
    elseif tX > X then
        if tY < Y then
            if (Y - tY) > 150 then
                if (tX - X) > 150 then
                    Rot = 2 --Up/right
                else
                    Rot = 1 --Up
                end
            elseif (Y - tY) > 30 then
                Rot = 2 --Up/right
            else
                Rot = 3 --Right
            end
        elseif tY == Y then
            Rot = 3 --Right
        elseif tY > Y then
            if (tY - Y) > 150 then
                if (tX - X) > 150 then
                    Rot = 4 --Down/right
                else
                    Rot = 5 --Down
                end
            elseif (tY - Y) > 30 then
                Rot = 4 --Down/right
            else
                Rot = 3 --Right
            end
        end
    end

    if indx == "turret" then
        turRotation = Rot
    else
        if state == "avoid" then
            myEnemies[indx].ROT = Rot + 4
            if myEnemies[indx].ROT > 8 then
                dif = myEnemies[indx].ROT - 8
                myEnemies[indx].ROT = 0 + dif
            end
        else
            myEnemies[indx].ROT = Rot
        end
    end
end


--=======================================
-- function:  DamageFireWallCheck(entity, indx, x, y)
-- author:    Nick Carlson
-- created:   February 11, 2005
-- returns:   nothing (process)
-- descrip:   checks for collisions with the wall
--=======================================
function DamageFireWallCheck(entity, indx, x, y)
--entity can either be "enemy" or "projectile"
--indx is the myEnemies or myProjectiles index of the object
--x is the X coordinate
--y is the Y coordinate

    collision = NO
    --Set local variables to global values
    if entity == "projectile" then
        width = 4
    else
        width = 20
    end

    if ((x + width) < 180) or (x > 200) or ((y + width) < 200) or (y > 420) then
        --No collision
    else
        collision = YES
        if entity == "player" then
            --Delete the player's ship
            DeleteItem(GUI_RUNTIME_SPRITES + 100)
            alive = "no"
        elseif entity == "enemy" then
            --Delete the enemy's ship
            DeleteItem(myEnemies[indx].ID)
            myEnemies[indx].XTHRUST = nil
            myEnemies[indx].YTHRUST = nil
            myEnemies[indx].ROT = nil
            myEnemies[indx].EX = nil
            myEnemies[indx].EY = nil
            myEnemies[indx].ID = nil
            ItemCommand(GUI_INGAME + 202, "SetString", "Enemy Damage: 00%")
            --Respawns the enemy
            DamageFireEnemyInit()
        else
            --Deletes the projectile and clears its table indexes
            DeleteItem(myProjectiles[indx].PROJ_ID)
            myProjectiles[indx].PROJ_X = nil
            myProjectiles[indx].PROJ_Y = nil
            myProjectiles[indx].PROJ_XTH = nil
            myProjectiles[indx].PROJ_YTH = nil
            myProjectiles[indx].PROJ_ID = nil
        end
    end
    return collision
end


--=======================================
-- function:  DamageFireDrawShip(myRot, x, y)
-- author:    Paul Schuytema
-- created:   February 1, 2004
-- returns:   nothing (process)
-- descrip:   refreshes the image of the player's ship
--=======================================
function DamageFireDrawShip(myRot, x, y)
--myRot is the rotation of the player's ship
--x is the X coordinate of the player's ship
--y is the Y coordinate of the player's ship

    DeleteItem(GUI_RUNTIME_SPRITES + 100)
    shipName = string.format("%s%d%s", "ship", myRot, ".bmp")
    myX = myX + x
    myY = myY + y
    --Checks for collision and displays new image
    CollisionCheck("player", myX, myY)
    CreateItem(GUI_RUNTIME_SPRITES + 100, "Sprite", shipName);
    SetItemPosition(GUI_RUNTIME_SPRITES + 100, myX, myY, 20, 20)
    --Checks for player's contact with enemies or enemy projectiles
    DamageFireCasualtyCheck()
    DamageFireWallCheck("player", 0, myX, myY)
end


--=======================================
-- function:  DamageFireDrawTurret(turRot, turX, turY)
-- author:    Paul Schuytema
-- created:   February 1, 2004
-- returns:   nothing (process)
-- descrip:   refreshes the image of the turret
--=======================================
function DamageFireDrawTurret(turRot, turX, turY)
--myRot is the rotation of the turret
--turX is the X coordinate of the turret
--turY is the Y coordinate of the turret

    DeleteItem(GUI_RUNTIME_SPRITES + 102)
    turName = string.format("%s%d%s", "turret", turRot, ".bmp")
    CreateItem(GUI_RUNTIME_SPRITES + 102, "Sprite", turName)
    SetItemPosition(GUI_RUNTIME_SPRITES + 102, turX, turY, 20, 20)
end


--=======================================
-- function:  DamageFireTurretFacing()
-- author:    Nick Carlson
-- created:   February 11, 2005
-- returns:   nothing (process)
-- descrip:   calculates the actions of the turret
--=======================================
function DamageFireTurretFacing()

    --Determine distance from player
    playerDistance = math.sqrt(((turX + 10) - (myX + 10))^2 + ((turY + 10) - (myY + 10))^2)
    enemyDistance = 10000
    tX = myX + 10
    tY = myY + 10
    for i = 1,enemyCount do
        if myEnemies[i].ID ~= nil then --Enemy exists
            --Determine distance from closest enemy
            tempEnemyDistance = math.sqrt(((turX + 10) - (myEnemies[i].EX + 10))^2 + ((turY + 10) - (myEnemies[i].EY + 10))^2)
            if tempEnemyDistance < enemyDistance then
                enemyDistance = tempEnemyDistance
                --Evaluate for the closest option
                if enemyDistance < playerDistance then
                    tX = myEnemies[i].EX + 10
                    tY = myEnemies[i].EY + 10
                end
            end
        end
        turFireCounter = turFireCounter + 1
        if turFireCounter == 5 then
            DamageFireFireProjectile(0, 0)
            turFireCounter = 0
        end
    end
    DamageFireSetTravelDirection("turret", "off", tX, tY)
end


--=======================================
-- function:  DamageFireProjectileInit()
-- author:    Nick Carlson
-- created:   February 11, 2005
-- returns:   nothing (process)
-- descrip:   creates myProjectiles table
--=======================================
function DamageFireProjectileInit()

    pCount = 50 --Number of projectiles in the game
    pIndx = 0 --Index of projectile in the myProjectiles table

    myProjectiles = {} --Creates myProjectiles table

    --Creates table, one entry per potential projectile
    for indx = 1,pCount do
        --Creates a table to hold the data for each projectile
        myProjectiles[indx] = {}
        myProjectiles[indx].PROJ_ID = 0--GUI identification number (#)
        myProjectiles[indx].PROJ_XTH = 0 --Thrust along the x-axis (#)
        myProjectiles[indx].PROJ_YTH = 0 --Thrust along the y-axis (#)
        myProjectiles[indx].PROJ_X = 0 --X coordinate (#)
        myProjectiles[indx].PROJ_Y = 0 --Y coordinate (#)
    end
end


--=======================================
-- function:  DamageFireFireProjectile(ship, xThrust, yThrust)
-- author:    Nick Carlson
-- created:   February 11, 2005
-- returns:   nothing (process)
-- descrip:   creates a projectile and indexs it in myProjectiles table
--=======================================
function DamageFireFireProjectile(xThrust, yThrust)
--xThrust is the projectile's thrust along the x-axis
--yThrust is the projectile's thrust along the y-axis

    pIndx = pIndx + 1
    myProjectiles[pIndx].PROJ_ID = GUI_RUNTIME_SPRITES + pIndx + 299 --Starts IDs at 300 (not including offset)
    --Turret's projectile
    myProjectiles[pIndx].PROJ_X = turX
    myProjectiles[pIndx].PROJ_Y = turY
    Rot = turRotation
    CreateItem(myProjectiles[pIndx].PROJ_ID, "Sprite", "box1.bmp")

    --Set the projectile's position and thrust
    if Rot == 1 then --Up
        myProjectiles[pIndx].PROJ_X = myProjectiles[pIndx].PROJ_X + 8
        myProjectiles[pIndx].PROJ_Y = myProjectiles[pIndx].PROJ_Y
        myProjectiles[pIndx].PROJ_XTH = xThrust
        myProjectiles[pIndx].PROJ_YTH = yThrust - 10
    end
    if Rot == 2 then --Up/right
        myProjectiles[pIndx].PROJ_X = myProjectiles[pIndx].PROJ_X + 18
        myProjectiles[pIndx].PROJ_Y = myProjectiles[pIndx].PROJ_Y
        myProjectiles[pIndx].PROJ_XTH = xThrust + 10
        myProjectiles[pIndx].PROJ_YTH = yThrust - 10
    end
    if Rot == 3 then --Right
        myProjectiles[pIndx].PROJ_X = myProjectiles[pIndx].PROJ_X + 18
        myProjectiles[pIndx].PROJ_Y = myProjectiles[pIndx].PROJ_Y + 8
        myProjectiles[pIndx].PROJ_XTH = xThrust + 10
        myProjectiles[pIndx].PROJ_YTH = yThrust
    end
    if Rot == 4 then --Down/right
        myProjectiles[pIndx].PROJ_X = myProjectiles[pIndx].PROJ_X + 18
        myProjectiles[pIndx].PROJ_Y = myProjectiles[pIndx].PROJ_Y + 18
        myProjectiles[pIndx].PROJ_XTH = xThrust + 10
        myProjectiles[pIndx].PROJ_YTH = yThrust + 10
    end
    if Rot == 5 then --Down
        myProjectiles[pIndx].PROJ_X = myProjectiles[pIndx].PROJ_X + 8
        myProjectiles[pIndx].PROJ_Y = myProjectiles[pIndx].PROJ_Y + 18
        myProjectiles[pIndx].PROJ_XTH = xThrust
        myProjectiles[pIndx].PROJ_YTH = yThrust + 10
    end
    if Rot == 6 then --Down/left
        myProjectiles[pIndx].PROJ_X = myProjectiles[pIndx].PROJ_X - 2
        myProjectiles[pIndx].PROJ_Y = myProjectiles[pIndx].PROJ_Y + 18
        myProjectiles[pIndx].PROJ_XTH = xThrust - 10
        myProjectiles[pIndx].PROJ_YTH = yThrust + 10
    end
    if Rot == 7 then --Left
        myProjectiles[pIndx].PROJ_X = myProjectiles[pIndx].PROJ_X - 2
        myProjectiles[pIndx].PROJ_Y = myProjectiles[pIndx].PROJ_Y + 8
        myProjectiles[pIndx].PROJ_XTH = xThrust - 10
        myProjectiles[pIndx].PROJ_YTH = yThrust
    end
    if Rot == 8 then --Up/left
        myProjectiles[pIndx].PROJ_X = myProjectiles[pIndx].PROJ_X - 2
        myProjectiles[pIndx].PROJ_Y = myProjectiles[pIndx].PROJ_Y
        myProjectiles[pIndx].PROJ_XTH = xThrust - 10
        myProjectiles[pIndx].PROJ_YTH = yThrust - 10
    end

    --Update the display
    SetItemPosition(myProjectiles[pIndx].PROJ_ID, myProjectiles[pIndx].PROJ_XTH, myProjectiles[pIndx].PROJ_YTH, 4, 4)
    if pIndx == pCount then
        pIndx = 0
    end
end


--=======================================
-- function:  DamageFireDrawProjectile()
-- author:    Nick Carlson
-- created:   February 11, 2005
-- returns:   nothing (process)
-- descrip:   refreshes the image of the projectiles
--=======================================
function DamageFireDrawProjectile()

    for indx = 1, pCount do
        if myProjectiles[indx].PROJ_ID ~= nil then
            DeleteItem(myProjectiles[indx].PROJ_ID)
            --Turret's projectile
            CreateItem(myProjectiles[indx].PROJ_ID, "Sprite", "box1.bmp")
            myProjectiles[indx].PROJ_X = myProjectiles[indx].PROJ_X + myProjectiles[indx].PROJ_XTH
            myProjectiles[indx].PROJ_Y = myProjectiles[indx].PROJ_Y + myProjectiles[indx].PROJ_YTH
            SetItemPosition(myProjectiles[indx].PROJ_ID, myProjectiles[indx].PROJ_X, myProjectiles[indx].PROJ_Y, 4, 4)

            if DamageFireWallCheck("projectile", indx, myProjectiles[indx].PROJ_X, myProjectiles[indx].PROJ_Y) == NO then
            	--Deletes projectiles when they pass the world's boundaries
            	if (myProjectiles[indx].PROJ_X > 780) or (myProjectiles[indx].PROJ_X < 20) or (myProjectiles[indx].PROJ_Y > 580) or (myProjectiles[indx].PROJ_Y < 20) then
                	DeleteItem(myProjectiles[indx].PROJ_ID)
                	myProjectiles[indx].PROJ_X = nil
                	myProjectiles[indx].PROJ_Y = nil
                	myProjectiles[indx].PROJ_XTH = nil
                	myProjectiles[indx].PROJ_YTH = nil
                	myProjectiles[indx].PROJ_ID = nil
            	end
        	end
    	end
	end
end


--=======================================
-- function:  DamageFireEnemyHitCheck()
-- author:    Nick Carlson
-- created:   February 11, 2005
-- returns:   nothing (process)
-- descrip:   checks for collisions between the player's projectiles and the enemies
--=======================================
function DamageFireEnemyHitCheck()

    collisionCounter = 0 --Counts collisions and acts as an index in collisionTable table
    collisionTable = {}

    --Creates table, one entry per potential collision
    for indx = 1,pCount do
        --Creates a table to hold the data for each collision
        collisionTable[indx] = {}
        collisionTable[indx].DE_INDX = 0 --The myEnemies table index of the Dead Enemy (#)
        collisionTable[indx].DP_INDX = 0 --The myProjectiles table index of the Dead Projectile (#)
    end

    for i = 1,enemyCount do
        if myEnemies[i].ID ~= nil then
            for j = 1, pCount do
                if myProjectiles[j].PROJ_ID ~= nil then
                    if ((myEnemies[i].EX + 20) < myProjectiles[j].PROJ_X) or (myEnemies[i].EX > (myProjectiles[j].PROJ_X + 4)) or ((myEnemies[i].EY + 20) < myProjectiles[j].PROJ_Y) or (myEnemies[i].EY > (myProjectiles[j].PROJ_Y + 4)) then
                        --No collision
                    else
                        --Collision
                        collisionCounter = collisionCounter + 1
                        collisionTable[collisionCounter].DE_INDX = i --Indexes the myEnemies index of the dead enemy
                        collisionTable[collisionCounter].DP_INDX = j --Indexes the myProjectiles index of the dead projectile
                    end
                end
            end
        end
    end
    --Sorts through the collisionTable table
    for indx = 1,collisionCounter do
        myDeadEnemyIndx = collisionTable[indx].DE_INDX
        myDeadProjectileIndx = collisionTable[indx].DP_INDX
        if (myEnemies[myDeadEnemyIndx].ID ~= nil) and (myProjectiles[myDeadProjectileIndx].PROJ_ID ~= nil) then --Both exist
            myEnemies[myDeadEnemyIndx].DAMAGE = myEnemies[myDeadEnemyIndx].DAMAGE + 1
            if (myEnemies[myDeadEnemyIndx].DAMAGE < 9) then
                local percentage = ((myEnemies[myDeadEnemyIndx].DAMAGE/9) * 100)
                ItemCommand(GUI_INGAME + 202, "SetString", string.format("%s%d%s", "Enemy Damage: ", percentage, "%"))
            else
                --Deletes the enemy and clears its table indexes
                DeleteItem(myEnemies[myDeadEnemyIndx].ID)
                myEnemies[myDeadEnemyIndx].XTHRUST = nil
                myEnemies[myDeadEnemyIndx].YTHRUST = nil
                myEnemies[myDeadEnemyIndx].ROT = nil
                myEnemies[myDeadEnemyIndx].EX = nil
                myEnemies[myDeadEnemyIndx].EY = nil
                myEnemies[myDeadEnemyIndx].ID = nil
                ItemCommand(GUI_INGAME + 202, "SetString", "Enemy Damage: 00%")

                --Respawns the enemy
                DamageFireEnemyInit()

                --Deletes the projectile and clears its table indexes
                DeleteItem(myProjectiles[myDeadProjectileIndx].PROJ_ID)
                myProjectiles[myDeadProjectileIndx].PROJ_X = nil
                myProjectiles[myDeadProjectileIndx].PROJ_Y = nil
                myProjectiles[myDeadProjectileIndx].PROJ_XTH = nil
                myProjectiles[myDeadProjectileIndx].PROJ_YTH = nil
                myProjectiles[myDeadProjectileIndx].PROJ_ID = nil
            end
        end
    end
end


--=======================================
-- function:  DamageFireCasualtyCheck()
-- author:    Nick Carlson
-- created:   February 11, 2005
-- returns:   nothing (process)
-- descrip:   checks for collisions with the player
--=======================================
function DamageFireCasualtyCheck()

    --Collisions with enemies
    for i = 1,enemyCount do
        if myEnemies[i].ID ~= nil then
            if ((myEnemies[i].EX + 20) < myX) or (myEnemies[i].EX > (myX + 20)) or ((myEnemies[i].EY + 20) < myY) or (myEnemies[i].EY > (myY + 20)) then
                --No collision
            else
                --Collision
                --Delete the player's ship
                DeleteItem(GUI_RUNTIME_SPRITES + 100)
                alive = "no"
                myEnemies[i].DAMAGE = myEnemies[i].DAMAGE + 1

                if (myEnemies[i].DAMAGE < 9) then
                    local percentage = ((myEnemies[i].DAMAGE/9) * 100)
                    ItemCommand(GUI_INGAME + 202, "SetString", string.format("%s%d%s", "Enemy Damage: ", percentage, "%"))
                else
                    --Deletes the enemy and clears its table indexes
                    DeleteItem(myEnemies[i].ID)
                    myEnemies[i].XTHRUST = nil
                    myEnemies[i].YTHRUST = nil
                    myEnemies[i].ROT = nil
                    myEnemies[i].EX = nil
                    myEnemies[i].EY = nil
                    myEnemies[i].ID = nil
                    ItemCommand(GUI_INGAME + 202, "SetString", "Enemy Damage: 00%")

                    --Respawns the enemy
                    DamageFireEnemyInit()
                end
            end
        end
    end

    --Collisions with projectiles
    for i = 1,pCount do
        if myProjectiles[i].PROJ_ID ~= nil then
            if ((myX + 20) < myProjectiles[i].PROJ_X) or (myX > (myProjectiles[i].PROJ_X + 4)) or ((myY + 20) < myProjectiles[i].PROJ_Y) or (myY > (myProjectiles[i].PROJ_Y + 4)) then
                --No collision
            else
                --Collision
                --Delete the player's ship
                DeleteItem(GUI_RUNTIME_SPRITES + 100)
                alive = "no"

                --Deletes the projectile and clears its table indexes
                DeleteItem(myProjectiles[i].PROJ_ID)
                myProjectiles[i].PROJ_X = nil
                myProjectiles[i].PROJ_Y = nil
                myProjectiles[i].PROJ_XTH = nil
                myProjectiles[i].PROJ_YTH = nil
                myProjectiles[i].PROJ_ID = nil
            end
        end
    end
end


--Initial run sets the event handler
SetEventHandler("DamageFireEvent")


--Event handler
function DamageFireEvent(id, eventCode)

	if (eventCode == GUI_REENTER_INTERFACE)  or (eventCode == GUI_ENTER_INTERFACE) then
        for indx = 11,21 do
            world[indx][10] = 1
        end
        MakeWorld()
        DamageFireSetUp()
        DamageFireEnemyInit()
        DamageFireProjectileInit()
        StartTimer(refreshRate)
    end

    if eventCode == GUI_KEY_PRESS then
    	if id == 27 then --Esc
            for indx = 1,pCount do
                if myProjectiles[indx].PROJ_ID ~= nil then
                    DeleteItem(myProjectiles[indx].PROJ_ID)
                end
            end
            for indx = 100,103 do
                DeleteItem(GUI_RUNTIME_SPRITES + indx)
            end
            for indx = 11,21 do
                world[indx][10] = 0
            end
            RunGUI("GUI_MainMenu.lua")
    	end

        if id == 91 then -- [
            --Turns player's ship counterclockwise
            myRotation = myRotation - 1
            if myRotation < 1 then
                myRotation = 8
            end
        end

        if id == 93 then -- ]
            --Turns player's ship clockwise
            myRotation = myRotation + 1
            if myRotation > 8 then
                myRotation = 1
            end
        end

        if id == 32 then --Space bar
            --Increases the player's thrust
            if myRotation == 1 then
                myYThrust = myYThrust - 1
            end
            if myRotation == 2 then
                myYThrust = myYThrust - 1
                myXThrust = myXThrust + 1
            end
            if myRotation == 3 then
                myXThrust = myXThrust + 1
            end
            if myRotation == 4 then
                myYThrust = myYThrust + 1
                myXThrust = myXThrust + 1
            end
            if myRotation == 5 then
                myYThrust = myYThrust + 1
            end
            if myRotation == 6 then
                myYThrust = myYThrust + 1
                myXThrust = myXThrust - 1
            end
            if myRotation == 7 then
                myXThrust = myXThrust - 1
            end
            if myRotation == 8 then
                myYThrust = myYThrust - 1
                myXThrust = myXThrust - 1
            end
            if myYThrust > 5 then
                myYThrust = 5
            end
            if myYThrust < -5 then
                myYThrust = -5
            end
            if myXThrust > 5 then
                myXThrust = 5
            end
            if myXThrust < -5 then
                myXThrust = -5
            end
        end
    end


    if eventCode == GUI_TIMER_EXPIRED then
        if alive == "yes" then
            --Refreshes the player's ship image
            DamageFireDrawShip(myRotation, myXThrust, myYThrust)
        else
            --Respawns the player after a certain period
            respawnCounter = respawnCounter + 1
            if respawnCounter == respawnInterval then
                myRotation = 1
                myXThrust = 0
                myYThrust = 0
                myX = math.random(20,760)
                myY = math.random(20,560)
                respawnCounter = 0
                alive = "yes"
            end
        end

        --Directs each enemy based on its own REACT setting
        timeCounter = timeCounter + 1
        for indx = 1,enemyCount do
            if (timeCounter/myEnemies[indx].REACT) == (math.floor(timeCounter/myEnemies[indx].REACT)) then
                DamageFireEnemyFacing(indx)
            end
        end
        DamageFireTurretFacing()

        --Updates entities
        DamageFireDrawProjectile()
        DamageFireDrawEnemyShip()
        DamageFireDrawTurret(turRotation, turX, turY)
        --Checks for various collisions
        DamageFireEnemyHitCheck()
        --Resets the timer
        StartTimer(refreshRate)
    end
end
