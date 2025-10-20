#include "Hook_ParseMessage.hpp"

#include <CS2/SDK/SDK.hpp>
#include <CS2/SDK/Interface/CSoundOpSystem.hpp>
#include <CS2/SDK/Network/CNetworkMessages.hpp>
#include <CS2/SDK/Math/Vector3.hpp>

#include <CS2/Protobuf/gameevents.pb.h>

#include <AndromedaClient/CAndromedaClient.hpp>

auto Hook_CDemoRecorder( CDemoRecorder* pDemoRecorder , CNetworkSerializerPB* pSerializer , CNetMessagePB* pNetMessage ) -> bool
{
	if ( pSerializer->messageID == GE_SosStartSoundEvent )
	{
		CMsgSosStartSoundEvent* pMessage = reinterpret_cast<CMsgSosStartSoundEvent*>( (PBYTE)pNetMessage + 0x28 );

		if ( pMessage )
		{
			std::string SoundName = "null";
			Vector3 SoundPos;
			auto SourceEntityIndex = 0;

			if ( pMessage->has_source_entity_index() )
				SourceEntityIndex = pMessage->source_entity_index();

			if ( pMessage->has_packed_params() && pMessage->packed_params().size() >= 19 && pMessage->packed_params().data() )
				SoundPos = *(Vector3*)( pMessage->packed_params().data() + 7 );

			const char* szSoundEventName = SDK::Interfaces::SoundOpSystem()->GetCSoundEventManager()->GetSoundEventName( pMessage->soundevent_hash() );

			if ( szSoundEventName )
				SoundName = szSoundEventName;

			DEV_LOG( "StartSoundEvent: %i , %s\n" , SourceEntityIndex , SoundName.c_str() );
		}
	}

	return CDemoRecorder_o( pDemoRecorder , pSerializer , pNetMessage );
}
