// PiControlGetDeviceStack 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PiControlGetDeviceStack(int a1, int a2, int a3, unsigned int *a4)
{
  int v4; // r0
  int v5; // r7
  unsigned int v6; // r6
  int v7; // r5
  unsigned __int16 *v8; // r9
  int v9; // r0
  int i; // r0
  int ***v11; // r0
  int **v12; // r1
  int v13; // r4
  int *v14; // r4
  unsigned int v15; // r2
  _WORD *v16; // r10
  int v17; // r8
  int v18; // r7
  int v19; // r1
  __int64 v20; // kr00_8
  unsigned int j; // r6
  int v22; // r2
  unsigned int v23; // r7
  _WORD *v24; // r10
  unsigned int v25; // r8
  unsigned int v26; // r0
  int *v27; // r1 OVERLAPPED
  int v29; // [sp+8h] [bp-48h] BYREF
  unsigned int v30; // [sp+Ch] [bp-44h]
  int v31; // [sp+10h] [bp-40h]
  int v32; // [sp+14h] [bp-3Ch]
  unsigned int *v33; // [sp+18h] [bp-38h]
  int v34; // [sp+1Ch] [bp-34h]
  int *v35; // [sp+20h] [bp-30h] BYREF
  int **v36; // [sp+24h] [bp-2Ch]
  __int64 v37[5]; // [sp+28h] [bp-28h] BYREF

  v4 = *(_DWORD *)(a1 + 16);
  v36 = &v35;
  v5 = a3;
  v6 = a2;
  v7 = 0;
  v35 = (int *)&v35;
  v32 = a3;
  v33 = a4;
  v31 = a2;
  v8 = 0;
  v9 = IoGetDeviceAttachmentBaseRef(v4);
  v34 = v9;
  if ( v9 )
  {
    for ( i = IoGetAttachedDeviceReference(v9); ; i = IoGetLowerDeviceObject(v13) )
    {
      v13 = i;
      if ( !i )
        break;
      v11 = (int ***)ExAllocatePoolWithTag(1, 12, 1198550608);
      if ( !v11 )
      {
        ObfDereferenceObject(v13);
        v7 = -1073741670;
        goto LABEL_49;
      }
      v11[2] = (int **)v13;
      v12 = v36;
      *v11 = &v35;
      v11[1] = v12;
      if ( *v12 != (int *)&v35 )
        __fastfail(3u);
      *v12 = (int *)v11;
      v36 = (int **)v11;
    }
    v14 = v35;
    v15 = v6;
    v16 = (_WORD *)v5;
    v17 = 0;
    v30 = v6;
    if ( v35 == (int *)&v35 )
    {
LABEL_40:
      if ( v16 && v15 >= 2 )
      {
        *v16 = 0;
        v14 = v35;
      }
      v25 = v17 + 2;
      *v33 = v25;
      if ( !v5 || v25 > v6 )
        v7 = -1073741789;
      goto LABEL_46;
    }
    while ( 1 )
    {
      v18 = *(_DWORD *)(v14[2] + 8);
      if ( !v18 )
        break;
      if ( *(_DWORD *)(v18 + 32) && *(unsigned __int16 *)(v18 + 28) >= 2u )
      {
        v20 = *(_QWORD *)(v18 + 28);
        v19 = HIDWORD(v20);
        v37[0] = v20;
        for ( j = (unsigned __int16)v20; j >= 2 && !*(_WORD *)(HIDWORD(v20) + 2 * (j >> 1) - 2); LOWORD(v37[0]) = j )
          j = (unsigned __int16)(j - 2);
      }
      else
      {
        RtlInitUnicodeString((unsigned int)v37, 0);
        v19 = HIDWORD(v37[0]);
        j = LOWORD(v37[0]);
      }
      if ( j )
        goto LABEL_32;
      v22 = 264;
      v29 = 264;
      if ( !v8 )
      {
        v8 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 264, 1198550608);
        if ( !v8 )
        {
          v7 = -1073741670;
LABEL_38:
          v14 = v35;
          if ( v7 >= 0 )
          {
            v15 = v30;
            v6 = v31;
            v5 = v32;
            goto LABEL_40;
          }
LABEL_46:
          if ( !v8 )
            goto LABEL_50;
          v26 = (unsigned int)v8;
          goto LABEL_48;
        }
        v22 = v29;
      }
      v7 = ObQueryNameStringMode(v18, (int)v8, v22, &v29, 0);
      if ( v7 < 0 || !v29 || *v8 < 2u )
      {
        RtlInitUnicodeString((unsigned int)v37, L"?");
        v7 = 0;
LABEL_30:
        v19 = HIDWORD(v37[0]);
        goto LABEL_31;
      }
      v19 = *((_DWORD *)v8 + 1);
      v37[0] = *(_QWORD *)v8;
LABEL_31:
      j = LOWORD(v37[0]);
LABEL_32:
      if ( v16 )
      {
        v23 = v30;
        if ( v30 >= j + 2 )
        {
          memmove((int)v16, v19, j);
          v24 = &v16[j >> 1];
          *v24 = 0;
          v16 = v24 + 1;
          v30 = v23 - j - 2;
        }
      }
      v14 = (int *)*v14;
      v17 += j + 2;
      if ( v14 == (int *)&v35 )
        goto LABEL_38;
    }
    RtlInitUnicodeString((unsigned int)v37, L"?");
    goto LABEL_30;
  }
  v7 = -1073741808;
LABEL_49:
  while ( 1 )
  {
    v14 = v35;
LABEL_50:
    if ( v14 == (int *)&v35 )
      break;
    *(_QWORD *)&v27 = *(_QWORD *)v14;
    if ( (int **)v14[1] != &v35 || (int *)v27[1] != v14 )
      __fastfail(3u);
    v35 = v27;
    v27[1] = (int)&v35;
    ObfDereferenceObject(v14[2]);
    v26 = (unsigned int)v14;
LABEL_48:
    ExFreePoolWithTag(v26);
  }
  if ( v34 )
    ObfDereferenceObject(v34);
  return v7;
}
