// ExpGetGlobalLocaleSection 
 
int __fastcall ExpGetGlobalLocaleSection(int *a1)
{
  int v2; // r4
  int v3; // r6
  unsigned int v5; // r6
  int v6; // r0
  int v7; // r7
  unsigned int v8; // r1
  int v9; // r7
  unsigned int v10; // r0
  int v11; // r0
  int v12; // r3
  int v13; // [sp+30h] [bp-260h]
  int v14; // [sp+38h] [bp-258h] BYREF

  v2 = NlsLocaleSectionPointer;
  if ( (unsigned int)NlsLocaleSectionPointer > 1 )
  {
    ObfReferenceObject(NlsLocaleSectionPointer);
    goto LABEL_3;
  }
  if ( ZwOpenKey() < 0 )
  {
LABEL_9:
    v3 = ZwOpenFile();
    if ( v3 < 0 )
      return v3;
    v3 = ZwCreateSection();
    ZwClose();
    if ( v3 < 0 )
      return v3;
    v3 = ObReferenceObjectByHandle(v13, 983071, MmSectionObjectType, 0, &v14);
    v2 = v14;
    ZwClose();
    if ( v3 < 0 )
      return v3;
    v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v5 + 308);
    v6 = KeAbPreAcquire((unsigned int)&NlsSectionLock, 0, 0);
    v7 = v6;
    do
      v8 = __ldrex((unsigned __int8 *)&NlsSectionLock);
    while ( __strex(v8 | 1, (unsigned __int8 *)&NlsSectionLock) );
    __dmb(0xBu);
    if ( (v8 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&NlsSectionLock, v6, (unsigned int)&NlsSectionLock);
    if ( v7 )
      *(_BYTE *)(v7 + 14) |= 1u;
    v9 = NlsLocaleSectionPointer;
    if ( NlsLocaleSectionPointer == 1 )
    {
      NlsTableVersion = 263424;
      ObfReferenceObject(v2);
      NlsLocaleSectionPointer = v2;
    }
    else if ( NlsLocaleSectionPointer )
    {
      ObfDereferenceObject(v2);
      v2 = v9;
      ObfReferenceObject(v9);
    }
    __dmb(0xBu);
    do
      v10 = __ldrex((unsigned int *)&NlsSectionLock);
    while ( __strex(v10 - 1, (unsigned int *)&NlsSectionLock) );
    if ( (v10 & 2) != 0 && (v10 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&NlsSectionLock);
    v11 = KeAbPostRelease((unsigned int)&NlsSectionLock);
    v12 = (__int16)(*(_WORD *)(v5 + 308) + 1);
    *(_WORD *)(v5 + 308) = v12;
    if ( !v12 && *(_DWORD *)(v5 + 100) != v5 + 100 && !*(_WORD *)(v5 + 310) )
      KiCheckForKernelApcDelivery(v11);
LABEL_3:
    *a1 = v2;
    return 0;
  }
  if ( ZwQueryValueKey() < 0 )
  {
    ZwClose();
    goto LABEL_9;
  }
  return sub_7E8A98();
}
