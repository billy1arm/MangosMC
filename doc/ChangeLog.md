MaNGOS MC Changelog
=====================
This change log references the relevant changes (bug and security fixes) done
in recent versions.

Incorporating the following:
Zero Rel21
One Rel21
Many Thanks to all the groups and individuals who contributed to this release.

* Some of the dependant file groups have been made into submodules
* i.e. all the dependant libraries (dep folder) and realmd
* Allow target 60 to use script target whenever required (c2551)
* fix .npc factionid command after creature_template change
* Fix BIH::intersectRay crash. Thanks TC
* Fix bug that cause AreaAura reaply because the code doesn't search the correct rank of it. (c2570)
* Fix Double to Float conversion warnings
* Fix issue with afk playerin duel logout request from client after 30 mins.
* Fix logic bug in SelectAuraRankForLevel (c2569)
* Fix raid instance reset crash and add a server command to force reset. Also added a new server command to force reset by an admin. (z2538)
* Fixing Chest Loot Issue
* Implement CREATURE_FLAG_EXTRA_ACTIVE (c2578)
* Implement TARGET_RANDOM_UNIT_CHAIN_IN_AREA (c2548) Also unify the TARGET_RANDOM_CHAIN_IN_AREA code
* Moved enum to correct position in list
* Remove invisibility aura (aura 18) based on attribute (c2553) Passive and negative invisibility auras are not removed on entering combat
* Some changes to Random chance calculation (c2567)
* Totally Cueergo Gold's Script updated
* Triage quest now doable but still nerve-racking
		

--------------------------------
Major changes for this build which require your attention when upgrading include:

Many Thanks to all the groups and individuals who contributed to this release.

* In the win folder there is a new solution "BuildEverything" which does just that.
  It builds the Core, Extraction Tools and Scripts library.
* From this release Eluna scripting has been added. Many thanks to the Eluna Team

* Added VS2013 support
Major changes for this build which require your attention when upgrading include
awesome things such as these:

  only. For Linux and FreeBSD users this means you can *always* use packages as
  provided by your distribution, and for Windows users this means you'll now
  have to download and install dependencies just once.
  We recommend that our Windows users pick up pre-built dependencies from
  [GNUWin32](http://gnuwin32.sourceforge.net/).
* The tools for map extraction and generation from the game client are finally
* The `genrevision` application has been removed from the build. Revision data
  and build information is now extracted via [Git](http://git-scm.com/) only.
* SOAP bindings for the world server are now optional, and will be disabled by
  available to enable the bindings.
* The output given by all map tools has been cleaned up, and will now give you
  useful information such as the map version, or complete usage instructions.
  Pass the `--help` parameter, and any map tool will provide usage instructions!
* Documentation has been rewritten and converted to **Markdown** format, which
  is readable and converts nicely to HTML when viewing in the repository browser.
* Documentation has been added for all map tools including usage instructions
  and examples.
* Player movement has been rewritten, and now factors in possible issues such as
  lag when sending out character movement. This also means, looting when moving
  is no longer possible, and will be canceled.
* Looting in groups has been corrected, and you should now be able to use round
  robin, master looter, free for all and need before greed looting.
* EventAI is now more verbose, and will validate targets for commands upon server
  start-up. It's very likely that you will see many more errors now. Additionally
  the `npc aiinfo` command will display more useful info.
* **ScriptDev2** has been merged into the server repository! You do not need to
  make a clone, and *may need to delete* previously checkouts of the scripts
  repository. This also means, *ScriptDev2* will now always be built when you

Also numerous minor fixes and improvements have been added, such as:

* Using potions for power types not used by a class will now raise the correct
  error messages, e.g. Warriors can no longer consume Mana potions.
* Hunter pets will receive full experience when their masters are grouped.
* Mobs fleeing will do so now in normal speed, instead of crazy speed.
* The world server will now provide improved, readable output on start-up, and
  less confusing messages for identical issues.
* In-game commands `goname` and `namego` have been replaced with `appear` and
  `summon`. If you happen to find other commands with weird naming, let us know!
* We have done extensive house-keeping and removed many TBC specific code parts,
  and replaced TBC specific values with the proper vanilla WoW counterparts.
  This includes the TBC spell modifiers, which now have been dropped and are no
  longer available.
* Unprivileged player accounts will no longer be able to execute mangos dot
  commands in the in-game chat. If you need this, enable `PlayerCommands` in
  the mangosd configuration. The default setting is off.


Also numerous minor fixes and improvements have been added, such as:

