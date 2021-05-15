// PiLookupInDDB 
 
int __fastcall PiLookupInDDB(int a1, int a2, int a3)
{
  int v4; // r0
  int v7; // r5
  char v9[16]; // [sp+28h] [bp-50h] BYREF
  int v10; // [sp+40h] [bp-38h]
  int v11; // [sp+44h] [bp-34h]
  char *v12; // [sp+48h] [bp-30h]
  int v13; // [sp+4Ch] [bp-2Ch]
  int v14; // [sp+50h] [bp-28h]
  int v15; // [sp+54h] [bp-24h]

  v4 = PpDDBHandle;
  if ( PpDDBHandle )
    return PiIsDriverBlocked(v4, a1, a2, a3);
  RtlInitUnicodeString((unsigned int)v9, (unsigned __int16 *)PiDDBPath);
  v10 = 24;
  v11 = 0;
  v12 = v9;
  v14 = 0;
  v15 = 0;
  v13 = 576;
  if ( ZwOpenFile() >= 0 )
  {
    v10 = 24;
    v11 = 0;
    v12 = 0;
    v14 = 0;
    v15 = 0;
    v13 = 576;
    v7 = ZwCreateSection();
    if ( v7 < 0 )
    {
      if ( (PiLoggedErrorEventsMask & 0x20) == 0 )
        JUMPOUT(0x7CD644);
      return v7;
    }
    v7 = ZwMapViewOfSection();
    if ( v7 < 0 )
    {
      if ( (PiLoggedErrorEventsMask & 0x40) == 0 )
        JUMPOUT(0x7CD658);
      return v7;
    }
    v4 = SdbInitDatabaseInMemory(0, 0);
    PpDDBHandle = v4;
    if ( !v4 )
    {
      v7 = -1073741823;
      if ( (PiLoggedErrorEventsMask & 0x80) == 0 )
        JUMPOUT(0x7CD65E);
      return v7;
    }
    return PiIsDriverBlocked(v4, a1, a2, a3);
  }
  return sub_7CD628();
}
