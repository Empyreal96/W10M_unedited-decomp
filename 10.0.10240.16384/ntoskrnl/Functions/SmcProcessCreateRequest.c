// SmcProcessCreateRequest 
 
int __fastcall SmcProcessCreateRequest(int a1, unsigned int a2, int a3, char a4)
{
  int v6; // r8
  int v7; // r9
  _BYTE *v8; // r0
  int v9; // r6
  int v10; // r0
  _DWORD *v11; // r0
  unsigned int v12; // r5
  unsigned int v13; // r4
  int v16; // [sp+4h] [bp-45Ch] BYREF
  int v17; // [sp+8h] [bp-458h]
  int v18; // [sp+Ch] [bp-454h]
  int v19; // [sp+10h] [bp-450h]
  unsigned int v20; // [sp+14h] [bp-44Ch]
  int v21; // [sp+18h] [bp-448h]
  _DWORD v22[272]; // [sp+20h] [bp-440h] BYREF

  v21 = a4;
  v19 = a1;
  v20 = a2;
  v6 = 0;
  v18 = 0;
  v17 = 0;
  v7 = -1;
  v16 = -1;
  v8 = memset(v22, 0, 1056);
  if ( a3 == 1056 )
  {
    if ( v21 )
    {
      if ( (a2 & 7) != 0 )
        ExRaiseDatatypeMisalignment(v8);
      if ( a2 >= MmUserProbeAddress )
        *(_BYTE *)MmUserProbeAddress = 0;
      *(_BYTE *)a2 = *(_BYTE *)a2;
      *(_BYTE *)(a2 + 1048) = *(_BYTE *)(a2 + 1048);
    }
    memmove((int)v22, a2, 0x420u);
    if ( LOBYTE(v22[0]) != 3 || (v22[0] & 0xFFFFFF00) != 0 || v22[5] )
    {
      v9 = -1073741811;
    }
    else
    {
      v9 = SmcCacheCreatePrepare(a1);
      if ( v9 >= 0 )
      {
        v10 = SmAlloc(896, 1631808883);
        v6 = v10;
        if ( v10 )
        {
          SmcCacheInitialize(v10);
          HIWORD(v22[263]) = 0;
          v9 = SmcCacheStart(v6, &v22[2], &v22[8]);
          if ( v9 >= 0 )
          {
            v9 = SmcCacheAdd(a1, v6, &v16);
            if ( v9 < 0 )
            {
              v7 = v16;
            }
            else
            {
              v6 = 0;
              v18 = 0;
              v17 = 1;
              v9 = 0;
              v7 = v16;
              *(_DWORD *)(a2 + 4) = v16;
            }
          }
        }
        else
        {
          v9 = -1073741670;
        }
      }
    }
  }
  else
  {
    v9 = -1073741306;
  }
  if ( v7 != -1 )
  {
    v11 = (_DWORD *)(a1 + 16 * (v7 & 0xF) + 4);
    __pld(v11);
    v12 = *v11 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v13 = __ldrex(v11);
    while ( v13 == v12 && __strex(v12 - 2, v11) );
    if ( v13 != v12 )
      ExfReleaseRundownProtection((unsigned __int8 *)v11);
  }
  if ( v6 )
  {
    SmcCacheCleanup(v6);
    ST_STORE<SM_TRAITS>::StDmSparseBitmapFree(v6);
  }
  return v9;
}
