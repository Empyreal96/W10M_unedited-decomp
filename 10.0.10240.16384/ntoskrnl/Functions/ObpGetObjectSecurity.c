// ObpGetObjectSecurity 
 
int __fastcall ObpGetObjectSecurity(int a1, unsigned int *a2, _BYTE *a3, char a4)
{
  int v4; // r7
  int v7; // r6
  unsigned int *v9; // r5
  unsigned int v10; // r0
  unsigned int v11; // r1
  bool v12; // zf
  int v13; // r6
  unsigned int *v15; // r2
  int v16; // r0
  unsigned int v17; // r1
  unsigned int v18; // r0
  int v19; // r0
  int v20; // r5
  int v21; // r7
  int v22; // r4
  unsigned int v23; // r2
  unsigned int *v24; // r7
  int v25; // r0
  int v26; // r4
  unsigned int v27; // r2
  unsigned int *v28; // r2
  int v29; // r4
  unsigned int v30; // r2
  int v31; // r0
  unsigned int v32; // r1
  int v33; // r3
  int v34; // r1
  int v35; // r0
  int v36; // [sp+18h] [bp-28h] BYREF
  int v37; // [sp+1Ch] [bp-24h] BYREF
  int v38; // [sp+20h] [bp-20h]

  v4 = a1 - 24;
  v38 = a4;
  v7 = ObTypeIndexTable[*(unsigned __int8 *)(a1 - 12) ^ (unsigned __int8)((unsigned __int16)(a1 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie];
  if ( *(int (__fastcall **)(int, int, _DWORD *, int, int, int *))(v7 + 108) == SeDefaultObjectMethod )
  {
    v9 = (unsigned int *)(a1 - 4);
    __pld((void *)(a1 - 4));
    v10 = *(_DWORD *)(a1 - 4);
    if ( (v10 & 7) != 0 )
    {
      do
      {
        do
          v11 = __ldrex(v9);
        while ( v11 == v10 && __strex(v10 - 1, v9) );
        __dmb(0xBu);
        if ( v11 == v10 )
          break;
        v10 = v11;
      }
      while ( (v11 & 7) != 0 );
    }
    v12 = (v10 & 7) == 1;
    v13 = v10 & 0xFFFFFFF8;
    if ( (v10 & 7) == 0 )
    {
      if ( v13 )
      {
        v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v23 + 308);
        v24 = (unsigned int *)(v4 + 8);
        v25 = KeAbPreAcquire((unsigned int)v24, 0, 0);
        v26 = v25;
        do
          v27 = __ldrex(v24);
        while ( !v27 && __strex(0x11u, v24) );
        __dmb(0xBu);
        if ( v27 )
          ExfAcquirePushLockSharedEx(v24, v25, (unsigned int)v24);
        if ( v26 )
          *(_BYTE *)(v26 + 14) |= 1u;
        v13 = *v9 & 0xFFFFFFF8;
        v28 = (unsigned int *)(v13 - 8);
        do
          v29 = __ldrex(v28);
        while ( __strex(v29 + 8, v28) );
        if ( v29 <= 0 )
          sub_7FC4A8();
        __dmb(0xBu);
        do
          v30 = __ldrex(v24);
        while ( v30 == 17 && __strex(0, v24) );
        if ( v30 != 17 )
          ExfReleasePushLockShared(v24);
        v31 = KeAbPostRelease((unsigned int)v24);
        v32 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v33 = (__int16)(*(_WORD *)(v32 + 0x134) + 1);
        *(_WORD *)(v32 + 308) = v33;
        if ( !v33 && *(_DWORD *)(v32 + 100) != v32 + 100 && !*(_WORD *)(v32 + 310) )
          KiCheckForKernelApcDelivery(v31);
        goto LABEL_12;
      }
      v12 = 0;
    }
    if ( !v12 )
    {
LABEL_8:
      *a2 = v13;
      *a3 = 0;
      return 0;
    }
    v15 = (unsigned int *)(v13 - 8);
    do
      v16 = __ldrex(v15);
    while ( __strex(v16 + 7, v15) );
    if ( v16 <= 0 )
      __fastfail(0xEu);
LABEL_12:
    __pld(v9);
    v17 = *v9;
    if ( (*v9 & 7) == 0 )
    {
      while ( v13 == (v17 & 0xFFFFFFF8) )
      {
        do
          v18 = __ldrex(v9);
        while ( v18 == v17 && __strex(v17 + 7, v9) );
        __dmb(0xBu);
        if ( v18 == v17 )
          goto LABEL_8;
        v17 = v18;
        if ( (v18 & 7) != 0 )
          break;
      }
    }
    ObDereferenceSecurityDescriptor(v13, 7);
    goto LABEL_8;
  }
  v37 = 31;
  v36 = ObpDefaultSecurityDescriptorLength;
  v19 = ExAllocatePoolWithTag(1, ObpDefaultSecurityDescriptorLength, 1901290063);
  *a2 = v19;
  if ( !v19 )
    return -1073741670;
  *a3 = 1;
  v20 = v38;
  v21 = v4 + 20;
  v22 = (*(int (__fastcall **)(int, int, int *, unsigned int, int *, int, _DWORD, int, int))(v7 + 108))(
          a1,
          1,
          &v37,
          *a2,
          &v36,
          v21,
          *(_DWORD *)(v7 + 76),
          v7 + 52,
          v38);
  if ( v22 == -1073741789 )
  {
    ExFreePoolWithTag(*a2);
    v34 = v36;
    *a3 = 0;
    ObpDefaultSecurityDescriptorLength = v34;
    v35 = ExAllocatePoolWithTag(1, v34, 1901290063);
    *a2 = v35;
    if ( v35 )
    {
      *a3 = 1;
      v22 = (*(int (__fastcall **)(int, int, int *, unsigned int, int *, int, _DWORD, int, int))(v7 + 108))(
              a1,
              1,
              &v37,
              *a2,
              &v36,
              v21,
              *(_DWORD *)(v7 + 76),
              v7 + 52,
              v20);
      goto LABEL_20;
    }
    return -1073741670;
  }
LABEL_20:
  if ( v22 < 0 )
  {
    ExFreePoolWithTag(*a2);
    *a3 = 0;
  }
  return v22;
}
