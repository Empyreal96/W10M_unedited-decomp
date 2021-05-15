// SepGetLearningModeObjectInformation 
 
_BYTE *__fastcall SepGetLearningModeObjectInformation(int a1, int a2)
{
  _BYTE *v2; // r5
  unsigned int v3; // r4
  int v4; // r2
  _BYTE *result; // r0
  int v6; // r3
  unsigned int v7; // r1
  unsigned int v8; // r1
  _BYTE *v9; // r2
  unsigned int v10; // r8
  unsigned int v11; // r6
  unsigned int v12; // r10
  _BYTE *v13; // r0
  _DWORD *v14; // r0
  unsigned int v15; // r9
  _DWORD *v16; // r0
  unsigned int v17; // [sp+0h] [bp-58h]
  _BYTE *v18; // [sp+4h] [bp-54h]
  unsigned __int16 *v19; // [sp+8h] [bp-50h]
  unsigned int v20; // [sp+Ch] [bp-4Ch]
  unsigned __int16 *v21; // [sp+10h] [bp-48h]
  _BYTE *v22; // [sp+20h] [bp-38h]
  int v23; // [sp+28h] [bp-30h]
  int v24; // [sp+30h] [bp-28h]

  v2 = (_BYTE *)a1;
  v22 = (_BYTE *)a1;
  v20 = 0;
  v19 = 0;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = SepGetCurrentLogLevel(a1);
  *v2 = 0;
  result = *(_BYTE **)(v3 + 1040);
  if ( !result || *((_DWORD *)result + 1) != v4 )
  {
    if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) == 1 )
    {
      if ( (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x4C) & 0x400) != 0
        || *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) == 1 )
      {
        v6 = 0;
      }
      else
      {
        v6 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x9C);
      }
      if ( !v6 )
        return 0;
      v7 = *(_DWORD *)(v6 + 20);
      if ( !v7 )
        return 0;
      if ( (v7 & 3) != 0 )
        ExRaiseDatatypeMisalignment(result);
      if ( v7 + 12 > MmUserProbeAddress || v7 + 12 < v7 )
        *(_BYTE *)MmUserProbeAddress = 0;
      if ( *(_DWORD *)v7 != -1395763957 )
        return 0;
      v17 = *(_DWORD *)(v7 + 4);
      __dmb(0xBu);
      v8 = *(_DWORD *)(v7 + 8);
      __dmb(0xBu);
      if ( (v17 & 3) != 0 )
        ExRaiseDatatypeMisalignment(&MmUserProbeAddress);
      v9 = (_BYTE *)MmUserProbeAddress;
      if ( v17 + 8 > MmUserProbeAddress || v17 + 8 < v17 )
      {
        *(_BYTE *)MmUserProbeAddress = 0;
        v9 = (_BYTE *)MmUserProbeAddress;
      }
      if ( (v8 & 3) != 0 )
        ExRaiseDatatypeMisalignment(&MmUserProbeAddress);
      if ( v8 + 8 > (unsigned int)v9 || v8 + 8 < v8 )
      {
        *v9 = 0;
        v9 = (_BYTE *)MmUserProbeAddress;
      }
      v23 = *(_DWORD *)v17;
      v10 = *(_DWORD *)(v17 + 4);
      v24 = *(_DWORD *)v8;
      v11 = *(_DWORD *)(v8 + 4);
      v12 = (unsigned __int16)HIWORD(*(_DWORD *)v17);
      if ( HIWORD(*(_DWORD *)v17) )
      {
        if ( (v10 & 1) != 0 )
          ExRaiseDatatypeMisalignment(&MmUserProbeAddress);
        if ( HIWORD(v23) + v10 > (unsigned int)v9 || HIWORD(v23) + v10 < v10 )
        {
          *v9 = 0;
          v9 = (_BYTE *)MmUserProbeAddress;
        }
      }
      if ( HIWORD(v24) )
      {
        if ( (v11 & 1) != 0 )
          ExRaiseDatatypeMisalignment(&MmUserProbeAddress);
        if ( HIWORD(v24) + v11 > (unsigned int)v9 || HIWORD(v24) + v11 < v11 )
          *v9 = 0;
      }
      v13 = (_BYTE *)ExAllocatePoolWithTag(1, 28);
      v18 = v13;
      if ( v13 )
      {
        memset(v13, 0, 28);
        v14 = (_DWORD *)ExAllocatePoolWithTag(1, 8);
        v15 = (unsigned int)v14;
        if ( v14 )
        {
          *v14 = 0;
          v14[1] = 0;
          v19 = (unsigned __int16 *)ExAllocatePoolWithTag(1, v12);
          if ( v19 )
          {
            v16 = (_DWORD *)ExAllocatePoolWithTag(1, 8);
            v20 = (unsigned int)v16;
            if ( v16 )
            {
              *v16 = 0;
              v16[1] = 0;
              v21 = (unsigned __int16 *)ExAllocatePoolWithTag(1, HIWORD(v24));
              if ( v21 )
              {
                memmove((int)v19, v10, v12);
                RtlInitUnicodeString(v15, v19);
                memmove((int)v21, v11, HIWORD(v24));
                RtlInitUnicodeString(v20, v21);
                *((_DWORD *)v18 + 2) = v15;
                *((_DWORD *)v18 + 3) = v20;
                *v22 = 1;
                return v18;
              }
            }
          }
        }
        if ( v15 )
          ExFreePoolWithTag(v15);
        if ( v19 )
          ExFreePoolWithTag(v19);
        if ( v20 )
          ExFreePoolWithTag(v20);
        ExFreePoolWithTag(v18);
      }
    }
    result = 0;
  }
  return result;
}
