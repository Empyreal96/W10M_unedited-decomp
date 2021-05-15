// MmGetSessionMappedViewInformation 
 
int __fastcall MmGetSessionMappedViewInformation(int a1, int a2, unsigned int *a3, int a4)
{
  unsigned int *v4; // r4
  int v5; // r6
  int v6; // r3
  int v7; // r8
  unsigned int *v8; // r9
  unsigned int v9; // r10
  int v10; // r0
  int *v11; // r4
  int v12; // r5
  unsigned int v13; // r7
  int v14; // r0
  int v15; // r3
  int v16; // r2
  int v17; // r3
  int v18; // r3
  int v19; // r4
  int v21; // [sp+8h] [bp-58h] BYREF
  int v22; // [sp+Ch] [bp-54h] BYREF
  unsigned int *v23; // [sp+10h] [bp-50h]
  int *v24; // [sp+14h] [bp-4Ch]
  unsigned int v25; // [sp+18h] [bp-48h]
  int v26; // [sp+1Ch] [bp-44h]
  int v27; // [sp+20h] [bp-40h] BYREF
  char v28[56]; // [sp+28h] [bp-38h] BYREF

  v4 = a3;
  v23 = a3;
  v24 = (int *)a4;
  v25 = a2;
  if ( a2 )
  {
    v5 = ExLockUserBuffer(a1, a2, *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A), 1, &v22, &v21);
    if ( v5 < 0 )
      return v5;
    v6 = v21;
    v7 = v22;
    v4 = v23;
  }
  else
  {
    v7 = 0;
    v6 = 0;
  }
  v21 = v6;
LABEL_6:
  v5 = 0;
  v8 = 0;
  *v4 = 0;
  v9 = 0;
  v10 = MmGetNextSession();
  v11 = v24;
  while ( 1 )
  {
    v12 = v10;
    if ( !v10 )
      break;
    v13 = v9 + 20;
    v8 = (unsigned int *)(v7 + v9);
    v14 = MmGetSessionId(v10);
    v15 = *v11;
    v26 = v14;
    if ( v15 == -1 || v14 == v15 )
    {
      if ( MmAttachSession(v12, (int)v28, v14, v15) >= 0 )
      {
        if ( v13 < v9 )
        {
          MmDetachSession(v12, (int)v28, v16, v17);
          ObfDereferenceObject(v12);
          v4 = v23;
          goto LABEL_6;
        }
        v18 = v25;
        v9 += 20;
        if ( v13 <= v25 )
        {
          v19 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
          MiGetSystemPteStatistics(v19 + 8320, &v22, &v27);
          v8[3] = v22 << 12;
          v8[4] = v27 << 12;
          v8[1] = v26;
          v18 = *(_DWORD *)(v19 + 3216);
          v11 = v24;
          *v8 = v13;
          v8[2] = v18;
        }
        else
        {
          v5 = -1073741820;
        }
        MmDetachSession(v12, (int)v28, v16, v18);
      }
      if ( *v11 != -1 )
      {
        ObfDereferenceObject(v12);
        break;
      }
    }
    v10 = MmGetNextSession();
  }
  if ( v5 >= 0 && v8 )
    *v8 = 0;
  if ( v7 )
    ExUnlockUserBuffer(v21);
  *v23 = v9;
  return v5;
}
