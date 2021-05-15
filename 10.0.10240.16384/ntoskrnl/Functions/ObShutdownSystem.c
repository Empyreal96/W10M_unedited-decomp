// ObShutdownSystem 
 
int __fastcall ObShutdownSystem(int result)
{
  int v1; // r5
  _DWORD *v2; // r4
  int v3; // r0
  int v4; // r8
  int v5; // r7
  unsigned int v6; // r9
  unsigned int v7; // r3
  unsigned int *v8; // lr
  unsigned int *v9; // r6
  _DWORD *v10; // r3
  _DWORD *v11; // t1
  unsigned int *v12; // r1
  int v13; // r4
  int v14; // r2
  char v15; // r3
  int v16; // r10
  unsigned int v17; // r2
  unsigned __int8 *v18; // r4
  int v19; // r0
  int v20; // r8
  unsigned int v21; // r2
  int v22; // r3
  int v23; // r8
  int v24; // r1
  unsigned int v25; // r0
  unsigned int v26; // r2
  unsigned int v27; // r1
  __int16 v28; // r3
  unsigned int v29; // r0
  int v30; // r4
  int v31; // r3
  int v32; // r8
  int *v33; // r3
  int v34; // [sp+18h] [bp-40h] BYREF
  unsigned int v35; // [sp+1Ch] [bp-3Ch]
  unsigned int *v36; // [sp+20h] [bp-38h]
  int v37; // [sp+24h] [bp-34h]
  int v38; // [sp+28h] [bp-30h]
  int v39[10]; // [sp+30h] [bp-28h] BYREF

  if ( result )
  {
    if ( result == 1 )
    {
      v39[0] = 0;
      result = ExEnumHandleTable(*(_DWORD *)(PsInitialSystemProcess + 336), ObpShutdownCloseHandleProcedure, v39, 0);
    }
    else
    {
      v1 = ObpTypeObjectType;
      v2 = *(_DWORD **)ObpTypeObjectType;
      while ( v2 != (_DWORD *)v1 )
      {
        v3 = (int)(v2 + 10);
        v2 = (_DWORD *)*v2;
        v34 = v3;
        ObMakeTemporaryObject(v3);
      }
      RtlInitUnicodeString((unsigned int)v39, L"DosDevices");
      if ( ObReferenceObjectByName((int)v39, 64, 0, 0, ObpSymbolicLinkObjectType, 0, 0, &v34) >= 0 )
      {
        ObMakeTemporaryObject(v34);
        ObfDereferenceObject(v34);
      }
      RtlInitUnicodeString((unsigned int)v39, L"Global");
      if ( ObReferenceObjectByName((int)v39, 64, 0, 0, ObpSymbolicLinkObjectType, 0, 0, &v34) >= 0 )
      {
        ObMakeTemporaryObject(v34);
        ObfDereferenceObject(v34);
      }
      RtlInitUnicodeString((unsigned int)v39, L"GLOBALROOT");
      if ( ObReferenceObjectByName((int)v39, 64, 0, 0, ObpSymbolicLinkObjectType, 0, 0, &v34) >= 0 )
      {
        ObMakeTemporaryObject(v34);
        ObfDereferenceObject(v34);
      }
      ObfDereferenceObject(ObpRootDirectoryObject);
      ObfDereferenceObject(ObpDirectoryObjectType);
      ObfDereferenceObject(ObpSymbolicLinkObjectType);
      ObfDereferenceObject(ObpTypeDirectoryObject);
      result = ObfDereferenceObject(ObpTypeObjectType);
    }
    return result;
  }
  v4 = 0;
  v5 = ObpRootDirectoryObject;
  v37 = 0;
  v6 = 1;
  v35 = 1;
  if ( !ObpRootDirectoryObject )
    return result;
LABEL_15:
  while ( 2 )
  {
    v7 = 0;
    v8 = (unsigned int *)v5;
LABEL_16:
    v39[0] = v7;
    if ( v7 < 0x25 )
    {
      v9 = v8;
      v11 = (_DWORD *)*v8++;
      v10 = v11;
      v36 = v8;
      while ( 1 )
      {
        if ( !v10 )
        {
          v7 = v39[0] + 1;
          goto LABEL_16;
        }
        v12 = (unsigned int *)*v9;
        v13 = *(_DWORD *)(*v9 + 4);
        result = v13 - 24;
        v34 = v13;
        v14 = ObTypeIndexTable[(unsigned __int8)((unsigned __int16)(v13 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(v13 - 12)];
        v15 = *(_BYTE *)(v13 - 10);
        v38 = v14;
        v16 = (v15 & 2) != 0 ? result - ObpInfoMaskToOffset[v15 & 3] : 0;
        if ( v4 )
          break;
        if ( v14 == ObpTypeObjectType )
          goto LABEL_26;
        if ( v14 == ObpDirectoryObjectType )
        {
          v5 = v13;
          ++v6;
          goto LABEL_15;
        }
        v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v17 + 308);
        v18 = (unsigned __int8 *)(v13 - 16);
        v19 = KeAbPreAcquire(result + 8, 0, 0);
        v20 = v19;
        do
          v21 = __ldrex(v18);
        while ( __strex(v21 | 1, v18) );
        __dmb(0xBu);
        if ( (v21 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(v18, v19, (unsigned int)v18);
        if ( v20 )
          *(_BYTE *)(v20 + 14) |= 1u;
        v22 = v34;
        __pld(v18);
        v23 = v22 - 24;
        *(_BYTE *)(v22 - 9) &= 0xEFu;
        v24 = *(_DWORD *)v18;
        v25 = *(_DWORD *)v18 - 16;
        if ( (*(_DWORD *)v18 & 0xFFFFFFF0) <= 0x10 )
          v25 = 0;
        if ( (v24 & 2) != 0 )
          goto LABEL_41;
        __dmb(0xBu);
        do
          v26 = __ldrex((unsigned int *)v18);
        while ( v26 == v24 && __strex(v25, (unsigned int *)v18) );
        if ( v26 != v24 )
LABEL_41:
          ExfReleasePushLock(v18, v24);
        result = KeAbPostRelease((unsigned int)v18);
        v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v28 = *(_WORD *)(v27 + 0x134) + 1;
        *(_WORD *)(v27 + 308) = v28;
        if ( !v28 && *(_DWORD *)(v27 + 100) != v27 + 100 && !*(_WORD *)(v27 + 310) )
          result = KiCheckForKernelApcDelivery(result);
        if ( *(_DWORD *)(v23 + 4) )
        {
          v9 = (unsigned int *)*v9;
        }
        else
        {
          v29 = *v9;
          *v9 = *(_DWORD *)*v9;
          ExFreePoolWithTag(v29);
          v30 = v38;
          if ( (*(_BYTE *)(v38 + 42) & 8) != 0 )
          {
            v32 = v34;
          }
          else
          {
            v31 = v23 + 20;
            v32 = v34;
            (*(void (__fastcall **)(int, int, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD))(v38 + 108))(
              v34,
              2,
              0,
              0,
              0,
              v31,
              *(_DWORD *)(v38 + 76),
              0,
              0);
            v30 = v38;
          }
          if ( v30 == ObpSymbolicLinkObjectType )
          {
            v35 = v6;
            ObpDeleteSymbolicLinkName(v32);
            v9 = v36 - 1;
          }
          ExFreePoolWithTag(*(_DWORD *)(v16 + 8));
          *(_DWORD *)(v16 + 8) = 0;
          *(_WORD *)(v16 + 4) = 0;
          *(_WORD *)(v16 + 6) = 0;
          *(_DWORD *)v16 = 0;
          ObfDereferenceObject(v32);
          result = ObfDereferenceObject(v5);
        }
        v8 = v36;
LABEL_55:
        v10 = (_DWORD *)*v9;
        v4 = v37;
      }
      if ( v13 == v4 )
      {
        v37 = 0;
        if ( v35 > v6 )
        {
          v9 = v8 - 1;
          v35 = v6;
          goto LABEL_55;
        }
      }
LABEL_26:
      v9 = v12;
      goto LABEL_55;
    }
    --v6;
    if ( (*(_BYTE *)(v5 - 10) & 2) != 0 )
      v33 = (int *)(v5 - 24 - ObpInfoMaskToOffset[*(_BYTE *)(v5 - 10) & 3]);
    else
      v33 = 0;
    v4 = v5;
    v37 = v5;
    v5 = *v33;
    if ( *v33 )
      continue;
    return result;
  }
}
