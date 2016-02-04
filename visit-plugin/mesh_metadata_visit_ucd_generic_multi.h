/** This file is part of VLSV file format.
 * 
 *  Copyright 2014-2015 Finnish Meteorological Institute
 *  Copyright 2016 Arto Sandroos
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifndef MESH_METADATA_VISIT_UCD_GENERIC_MULTI_H
#define MESH_METADATA_VISIT_UCD_GENERIC_MULTI_H

#include <stdint.h>

#include <mesh_metadata.h>

namespace vlsvplugin {
   
   class UCDGenericMultiMeshMetadata: public MeshMetadata {
    public:
      UCDGenericMultiMeshMetadata();
      virtual ~UCDGenericMultiMeshMetadata();
      
      virtual bool getDomainInfoNodes(vlsv::Reader* vlsvReader,int domain,const uint64_t*& domainOffsets,
			                          const uint64_t*& ghostOffsets,const uint64_t*& variableOffsets);
      virtual bool getDomainInfoZones(vlsv::Reader* vlsvReader,int domain,const uint64_t*& domainOffsets,
			                          const uint64_t*& ghostOffsets,const uint64_t*& variableOffsets);
      virtual const uint64_t getCellConnectivitySize(int domain) const;
      virtual int getNodeDataSize() const;
      virtual vlsv::datatype::type getNodeDatatype() const;
      
      virtual bool read(vlsv::Reader* vlsvReader,const std::map<std::string,std::string>& attribs);
      
    protected:
      virtual const std::string& getCorrectVlsvMeshType() const;
      virtual bool readDomains(vlsv::Reader* vlsvReader);

      vlsv::datatype::type nodeDatatype; /**< Datatype for node coordinates.*/
      int nodeDataSize;                  /**< Byte size of nodeDatatype.*/
   };
   
} // namespace vlsvplugin

#endif
