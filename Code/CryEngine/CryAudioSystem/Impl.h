// Copyright 2001-2018 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#include <IImpl.h>

namespace CryAudio
{
namespace Impl
{
namespace Null
{
class CImpl final : public IImpl
{
public:

	CImpl(CImpl const&) = delete;
	CImpl(CImpl&&) = delete;
	CImpl& operator=(CImpl const&) = delete;
	CImpl& operator=(CImpl&&) = delete;

	CImpl() = default;

	// CryAudio::Impl::IImpl
	virtual void                Update() override;
	virtual ERequestStatus      Init(uint32 const objectPoolSize, uint32 const eventPoolSize) override;
	virtual void                ShutDown() override;
	virtual void                Release() override;
	virtual void                OnRefresh() override;
	virtual void                SetLibraryData(XmlNodeRef const pNode, bool const isLevelSpecific) override;
	virtual void                OnBeforeLibraryDataChanged() override;
	virtual void                OnAfterLibraryDataChanged() override;
	virtual ERequestStatus      OnLoseFocus() override;
	virtual ERequestStatus      OnGetFocus() override;
	virtual ERequestStatus      MuteAll() override;
	virtual ERequestStatus      UnmuteAll() override;
	virtual ERequestStatus      PauseAll() override;
	virtual ERequestStatus      ResumeAll() override;
	virtual ERequestStatus      StopAllSounds() override;
	virtual ERequestStatus      RegisterInMemoryFile(SFileInfo* const pFileInfo) override;
	virtual ERequestStatus      UnregisterInMemoryFile(SFileInfo* const pFileInfo) override;
	virtual ERequestStatus      ConstructFile(XmlNodeRef const pRootNode, SFileInfo* const pFileInfo) override;
	virtual void                DestructFile(IFile* const pIFile) override;
	virtual char const* const   GetFileLocation(SFileInfo* const pFileInfo) override;
	virtual void                GetInfo(SImplInfo& implInfo) const override;
	virtual ITrigger const*     ConstructTrigger(XmlNodeRef const pRootNode, float& radius) override;
	virtual ITrigger const*     ConstructTrigger(ITriggerInfo const* const pITriggerInfo) override;
	virtual void                DestructTrigger(ITrigger const* const pITrigger) override;
	virtual IParameter const*   ConstructParameter(XmlNodeRef const pRootNode) override;
	virtual void                DestructParameter(IParameter const* const pIParameter) override;
	virtual ISwitchState const* ConstructSwitchState(XmlNodeRef const pRootNode) override;
	virtual void                DestructSwitchState(ISwitchState const* const pISwitchState) override;
	virtual IEnvironment const* ConstructEnvironment(XmlNodeRef const pRootNode) override;
	virtual void                DestructEnvironment(IEnvironment const* const pIEnvironment) override;
	virtual ISetting const*     ConstructSetting(XmlNodeRef const pRootNode) override;
	virtual void                DestructSetting(ISetting const* const pISetting) override;
	virtual IObject*            ConstructGlobalObject() override;
	virtual IObject*            ConstructObject(CTransformation const& transformation, char const* const szName = nullptr) override;
	virtual void                DestructObject(IObject const* const pIObject) override;
	virtual IListener*          ConstructListener(CTransformation const& transformation, char const* const szName = nullptr) override;
	virtual void                DestructListener(IListener* const pIListener) override;
	virtual IEvent*             ConstructEvent(CEvent& event) override;
	virtual void                DestructEvent(IEvent const* const pIEvent) override;
	virtual IStandaloneFile*    ConstructStandaloneFile(CStandaloneFile& standaloneFile, char const* const szFile, bool const bLocalized, ITrigger const* pITrigger = nullptr) override;
	virtual void                DestructStandaloneFile(IStandaloneFile const* const pIStandaloneFile) override;
	virtual void                GamepadConnected(DeviceId const deviceUniqueID) override;
	virtual void                GamepadDisconnected(DeviceId const deviceUniqueID) override;
	virtual void                SetLanguage(char const* const szLanguage) override;

	// Below data is only used when INCLUDE_AUDIO_PRODUCTION_CODE is defined!
	virtual void GetFileData(char const* const szName, SFileData& fileData) const override;
	virtual void DrawDebugInfo(IRenderAuxGeom& auxGeom, float const posX, float& posY, bool const showDetailedInfo) override;
	// ~CryAudio::Impl::IImpl
};
} // namespace Null
} // namespace Impl
} // namespace CryAudio