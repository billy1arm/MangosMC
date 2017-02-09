/**
 * MaNGOS is a full featured server for World of Warcraft, supporting
 * the following clients: 1.12.x, 2.4.3, 3.3.5a, 4.3.4a and 5.4.8
 *
 * Copyright (C) 2005-2017  MaNGOS project <https://getmangos.eu>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * World of Warcraft, and all World of Warcraft or Warcraft art, images,
 * and lore are copyrighted by Blizzard Entertainment, Inc.
 */

#ifndef TRANSPORTS_H
#define TRANSPORTS_H

#include "GameObject.h"

#include <map>
#include <set>

typedef std::set<Unit*> UnitSet;

//Base class for all transporter types
class Transport : public GameObject
{
    public:

        explicit Transport();
        virtual ~Transport();

        bool AddPassenger(Unit* passenger);
        bool RemovePassenger(Unit* passenger);

        virtual void Update(uint32 update_diff, uint32 p_time) = 0;
        virtual void DeleteFromDB() override {}

        UnitSet const& GetPassengers() const { return m_passengers; }

    protected:
        UnitSet m_passengers;

};


class LocalTransport : public Transport
{
    public:
        explicit LocalTransport();
        virtual ~LocalTransport();
        bool Initialize(uint32 guid, Map* m);
        virtual void Update(uint32 update_diff, uint32 p_time) override {} //NYI
    private:
        uint32 m_period;
};


class GlobalTransport : public Transport
{
    public:
        explicit GlobalTransport();
        virtual ~GlobalTransport();
        virtual void Update(uint32 update_diff, uint32 p_time) override;

        bool Initialize(uint32 entry, uint32 period, std::string const& name);
        std::set<uint32> const* GetMapsUsed() const { return &m_mapsUsed; }

    private:
        bool GenerateWaypoints();
        void TeleportTransport(uint32 newMapid, float x, float y, float z);
        void UpdateForMap(Map const* map);
        void MoveToNextWayPoint();                          // move m_next/m_cur to next points

        struct WayPoint
        {
            WayPoint() : mapid(0), x(0), y(0), z(0), teleport(false) {}
#if defined(CLASSIC)
            WayPoint(uint32 _mapid, float _x, float _y, float _z, bool _teleport) :
                mapid(_mapid), x(_x), y(_y), z(_z), teleport(_teleport) {}
#endif
#if defined(TBC)
            WayPoint(uint32 _mapid, float _x, float _y, float _z, bool _teleport, uint32 _arrivalEventID = 0, uint32 _departureEventID = 0)
                : mapid(_mapid), x(_x), y(_y), z(_z), teleport(_teleport),
                  arrivalEventID(_arrivalEventID), departureEventID(_departureEventID)
            {
            }
#endif
            uint32 mapid;
            float x;
            float y;
            float z;
            bool teleport;
#if defined(TBC)
            uint32 arrivalEventID;
            uint32 departureEventID;
#endif
        };

        typedef std::map<uint32, WayPoint> WayPointMap;

#if defined(CLASSIC)
        WayPointMap m_WayPoints;
#endif
        WayPointMap::const_iterator m_curr;
        WayPointMap::const_iterator m_next;
#if defined(CLASSIC)
        std::set<uint32> m_mapsUsed;
#endif
        uint32 m_pathTime;
        uint32 m_timer;
#if defined(TBC)
        PlayerSet m_passengers;

    public:
        WayPointMap m_WayPoints;
#endif
        uint32 m_nextNodeTime;
        uint32 m_period;
#if defined(TBC)
    private:
        void TeleportTransport(uint32 newMapid, float x, float y, float z);
        void UpdateForMap(Map const* map);
        void DoEventIfAny(WayPointMap::value_type const& node, bool departure);
        void MoveToNextWayPoint();                          // move m_next/m_cur to next points
#endif
};
#endif
