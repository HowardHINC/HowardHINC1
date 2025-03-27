//Send a message to all player's in the middle of their screen
//This is really cool!
function broadcast(%str, %time)
{
	centerPrintAll(%str, %time);
}
//Helper function because I am new to this.
function createPositionTransform(%x, %y, %z)
{
	%vec = %x SPC %y SPC %z;
	%nullorientation = "0 0 0 0";
	return MatrixCreate(%vec, %nullorientation);
}

//Searches through the player list and tries to find the player with the given id
function getPlayer(%pid)
{
	for(%id = 0; %id < ClientGroup.getCount(); %id++)
	{
		%client = ClientGroup.getObject(%id);
		if(%pid == %client.getCharacterId())
		{
			return %client;
		}
	}
	return 0;
}

//Teleport a player to the given position
//pid - The player id, found using listPlayers();
//x,y,z are world coordinates
//Usage:
//teleport(4, 100, 100, 100);
//Teleports the player with playerid 4 to the position (100, 100, 100)
function teleport(%pid, %x, %y, %z)
{
	%client = getPlayer(%pid);
	if(%client != 0)
		%client.player.setTransform(createPositionTransform(%x, %y, %z));
}

//Teleports all to the given location
function teleportAll(%x, %y, %z)
{
	for(%id = 0; %id < ClientGroup.getCount(); %id++)
	{
		teleport(%id, %x, %y, %z);
	}
}