// BiConvertElementToRegistryData 
 
int __fastcall BiConvertElementToRegistryData(unsigned int a1, int *a2, unsigned int a3, int a4, unsigned int *a5, int *a6)
{
  int v6; // r9
  int v7; // r3
  int v8; // r5
  int *v10; // r8
  int v11; // r10
  unsigned int v12; // r2
  int v13; // t1
  unsigned int v15; // r4
  int v16; // r7
  unsigned int v17; // r6
  int v18; // r4
  int v19; // r7
  int v20; // r0
  unsigned int v21; // r6
  _WORD *v22; // r10
  unsigned int v23; // r4
  int v24; // r0
  int v25; // r0
  unsigned int v26; // r3
  _DWORD *v27; // r0
  unsigned int v28; // [sp+0h] [bp-30h] BYREF
  int v29; // [sp+4h] [bp-2Ch]
  _DWORD v30[10]; // [sp+8h] [bp-28h] BYREF

  v6 = 0;
  v7 = HIBYTE(a1) & 0xF;
  v8 = 0;
  v28 = 0;
  v10 = a2;
  switch ( v7 )
  {
    case 1:
      if ( *a2 == 6 )
        v25 = BiConvertQualifiedPartitionToBootEnvironment(a2, a3, &v28);
      else
        v25 = BiConvertNtDeviceToBootEnvironment(a2, a3, 0, (int *)&v28);
      v8 = v25;
      v6 = v28;
      if ( v25 < 0 )
        goto LABEL_44;
      v26 = *(_DWORD *)(v28 + 8);
      v19 = v26 + 16;
      if ( v26 >= 0xFFFFFFF0 )
      {
        v8 = -1073741811;
        goto LABEL_44;
      }
      v27 = (_DWORD *)ExAllocatePoolWithTag(1, v26 + 16, 1262764866);
      v21 = (unsigned int)v27;
      if ( !v27 )
      {
        v8 = -1073741801;
        goto LABEL_44;
      }
      *v27 = v10[1];
      v27[1] = v10[2];
      v27[2] = v10[3];
      v27[3] = v10[4];
      memmove((int)(v27 + 4), v6, *(_DWORD *)(v6 + 8));
      ExFreePoolWithTag(v6);
      v6 = 0;
      break;
    case 2:
      if ( (a3 & 1) == 0 )
      {
        v11 = 0;
        v12 = a3 >> 1;
        if ( a3 >> 1 )
        {
          while ( 1 )
          {
            v13 = *(unsigned __int16 *)a2;
            a2 = (int *)((char *)a2 + 2);
            if ( !v13 )
              break;
            if ( !--v12 )
              goto LABEL_25;
          }
          v11 = 1;
        }
LABEL_25:
        v19 = a3;
        if ( !v11 )
        {
          v19 = a3 + 2;
          if ( a3 + 2 < a3 )
            return -1073741675;
          v8 = 0;
        }
        v24 = ExAllocatePoolWithTag(1, v19, 1262764866);
        v21 = v24;
        if ( v24 )
        {
          memmove(v24, (int)v10, a3);
          if ( !v11 )
            *(_WORD *)(v19 + v21 - 2) = 0;
          break;
        }
        return -1073741801;
      }
LABEL_46:
      JUMPOUT(0x813DBE);
    case 4:
      if ( (a3 & 0xF) != 0 )
        goto LABEL_46;
      v15 = a3 >> 4;
      v16 = 0;
      v28 = a3 >> 4;
      v17 = 0;
      if ( a3 >> 4 )
      {
        v18 = (int)a2;
        while ( 1 )
        {
          RtlInitUnicodeString((unsigned int)v30, 0);
          v8 = RtlStringFromGUIDEx(v18, (int)v30, 1);
          if ( v8 < 0 )
            return v8;
          v16 += LOWORD(v30[0]) + 2;
          RtlFreeAnsiString(v30);
          ++v17;
          v18 += 16;
          if ( v17 >= v28 )
          {
            v15 = v28;
            break;
          }
        }
      }
      v19 = v16 + 2;
      v20 = ExAllocatePoolWithTag(1, v19, 1262764866);
      v21 = v20;
      if ( !v20 )
        return -1073741801;
      v29 = 0;
      v22 = (_WORD *)v20;
      if ( v15 )
      {
        do
        {
          v8 = RtlStringFromGUIDEx((int)v10, (int)v30, 1);
          if ( v8 < 0 )
            goto LABEL_42;
          v23 = LOWORD(v30[0]) + 2;
          memmove((int)v22, v30[1], v23);
          v22 = (_WORD *)((char *)v22 + v23);
          RtlFreeAnsiString(v30);
          v10 += 4;
        }
        while ( ++v29 < v28 );
      }
      *v22 = 0;
      break;
    default:
      return sub_813D88();
  }
  if ( v8 < 0 )
  {
LABEL_42:
    if ( !v21 )
      return v8;
    ExFreePoolWithTag(v21);
LABEL_44:
    if ( v6 )
      ExFreePoolWithTag(v6);
    return v8;
  }
  v8 = 0;
  *a5 = v21;
  *a6 = v19;
  return v8;
}
