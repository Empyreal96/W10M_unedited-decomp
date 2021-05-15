// ExpSetTimer2 
 
int __fastcall ExpSetTimer2(int a1, __int64 *a2, int *a3)
{
  int v4; // r8
  int v5; // r0
  int *v6; // r6
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int v10; // lr
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int v14; // r3
  int v15; // r4
  int v16; // r5
  int v18; // [sp+10h] [bp-58h] BYREF
  char v19; // [sp+14h] [bp-54h]
  int v20; // [sp+18h] [bp-50h]
  int *v21; // [sp+1Ch] [bp-4Ch]
  __int64 v22; // [sp+20h] [bp-48h]
  int v23; // [sp+28h] [bp-40h]
  __int64 v24; // [sp+30h] [bp-38h]
  int v25; // [sp+38h] [bp-30h] BYREF
  int v26; // [sp+3Ch] [bp-2Ch]
  int v27; // [sp+40h] [bp-28h]
  int v28; // [sp+44h] [bp-24h]

  v20 = a1;
  v23 = a1;
  v4 = 0;
  v5 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v18 = v5;
  v19 = v5;
  v22 = 0i64;
  v6 = 0;
  v21 = 0;
  if ( a2 )
  {
    if ( v5 )
    {
      if ( (unsigned int)a2 >= MmUserProbeAddress )
        a2 = (__int64 *)MmUserProbeAddress;
      v24 = *a2;
      v22 = v24;
      if ( a3 )
      {
        if ( ((unsigned __int8)a3 & 7) != 0 )
          ExRaiseDatatypeMisalignment(v5);
        if ( (unsigned int)(a3 + 4) > MmUserProbeAddress || a3 + 4 < a3 )
          *(_BYTE *)MmUserProbeAddress = 0;
        v7 = a3[1];
        v8 = a3[2];
        v9 = a3[3];
        v25 = *a3;
        v26 = v7;
        v27 = v8;
        v28 = v9;
        v6 = &v25;
        v21 = &v25;
        v5 = v18;
      }
      v10 = v20;
    }
    else
    {
      if ( a3 )
      {
        v11 = a3[1];
        v12 = a3[2];
        v13 = a3[3];
        v25 = *a3;
        v26 = v11;
        v27 = v12;
        v28 = v13;
        v6 = &v25;
        v5 = v18;
      }
      v10 = v20;
    }
    v4 = 1;
  }
  else
  {
    v10 = v20;
  }
  if ( v6 )
  {
    if ( *v6 )
      return -1073741583;
    v14 = v6[3];
    if ( v14 < 0 && (v14 & v6[2]) != -1 )
      return -1073741583;
  }
  v15 = ObReferenceObjectByHandle(v10, 2, ExpIRTimerObjectType, v5, &v18, 0);
  if ( v15 >= 0 )
  {
    v16 = v18;
    if ( v4 )
      KeSetTimer2(v18);
    else
      KeCancelTimer2(v18, 0);
    ObfDereferenceObjectWithTag(v16);
  }
  return v15;
}
