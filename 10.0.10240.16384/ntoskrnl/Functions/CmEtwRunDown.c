// CmEtwRunDown 
 
int __fastcall CmEtwRunDown(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r7
  int v7; // r5
  int v8; // r7
  int v9; // r6
  int j; // r4
  unsigned __int16 *v11; // r0
  unsigned int v12; // r9
  int v13; // r2
  int v14; // r4
  __int16 v16; // [sp+8h] [bp-C0h] BYREF
  int v17; // [sp+10h] [bp-B8h]
  int i; // [sp+14h] [bp-B4h]
  int v19; // [sp+18h] [bp-B0h]
  int v20[7]; // [sp+1Ch] [bp-ACh] BYREF
  char v21[8]; // [sp+40h] [bp-88h] BYREF
  char v22[8]; // [sp+48h] [bp-80h] BYREF
  int v23[10]; // [sp+50h] [bp-78h] BYREF
  int *v24; // [sp+78h] [bp-50h] BYREF
  int v25; // [sp+7Ch] [bp-4Ch]
  int v26; // [sp+80h] [bp-48h]
  int v27; // [sp+84h] [bp-44h]
  int v28; // [sp+88h] [bp-40h]
  int v29; // [sp+8Ch] [bp-3Ch]
  int v30; // [sp+90h] [bp-38h]
  int v31; // [sp+94h] [bp-34h]
  __int16 *v32; // [sp+98h] [bp-30h]
  int v33; // [sp+9Ch] [bp-2Ch]
  int v34; // [sp+A0h] [bp-28h]
  int v35; // [sp+A4h] [bp-24h]

  v4 = a3;
  v5 = a2;
  v16 = 0;
  v19 = a3;
  v17 = a2;
  if ( !a4 )
  {
    v23[1] = 0;
    v23[2] = 0;
    v23[0] = 0;
    v23[3] = 0;
    v24 = v23;
    v25 = 0;
    v26 = 20;
    v27 = 0;
    v32 = &v16;
    v33 = 0;
    v34 = 2;
    v35 = 0;
    v7 = CmpGetNextActiveHive(0);
    for ( i = v7; v7; i = v7 )
    {
      CmpLockRegistryExclusive();
      if ( v4 )
        CmpLogHiveRundownEvent(v7, a1);
      if ( v5 )
      {
        v8 = *(_DWORD *)(v7 + 1848);
        v9 = *(_DWORD *)(v7 + 1844);
        if ( v8 )
        {
          do
          {
            for ( j = *(_DWORD *)(v9 + 8); j; j = *(_DWORD *)(j + 4) )
            {
              v11 = (unsigned __int16 *)CmpConstructName(j - 12);
              v12 = (unsigned int)v11;
              if ( v11 )
              {
                v13 = *v11;
                v28 = *((_DWORD *)v11 + 1);
                v29 = 0;
                v30 = v13;
                v31 = 0;
                v23[4] = j - 12;
                EtwpLogKernelEvent((int *)&v24, a1, 3, 2329, 4200450);
                ExFreePoolWithTag(v12);
              }
            }
            v9 += 12;
            --v8;
          }
          while ( v8 );
          v7 = i;
          v4 = v19;
        }
        v5 = v17;
      }
      CmpUnlockRegistry();
      v7 = CmpGetNextActiveHive(v7);
    }
    RtlInitUnicodeString((unsigned int)v21, L"\\Registry\\Machine\\System\\Select");
    v20[1] = 24;
    v20[2] = 0;
    v20[4] = 576;
    v20[3] = (int)v21;
    v20[5] = 0;
    v20[6] = 0;
    if ( ZwOpenKey() >= 0 )
    {
      RtlInitUnicodeString((unsigned int)v22, L"Current");
      v14 = ZwQueryValueKey();
      ZwClose();
      if ( v14 >= 0 )
      {
        v20[0] = v23[9];
        v24 = v20;
        v25 = 0;
        v26 = 4;
        v27 = 0;
        EtwpLogKernelEvent((int *)&v24, a1, 1, 2339, 4200450);
      }
    }
  }
  v24 = (int *)&CmPerfCounters;
  v25 = 0;
  v26 = 88;
  v27 = 0;
  EtwpLogKernelEvent((int *)&v24, a1, 1, 2338, 4200450);
  return 0;
}
