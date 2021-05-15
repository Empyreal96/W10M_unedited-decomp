// CmpDoFileWrite 
 
int __fastcall CmpDoFileWrite(int a1, int a2, int a3, int a4, unsigned int a5, _DWORD *a6, char a7)
{
  int v7; // r8
  unsigned int v8; // r1
  unsigned int v9; // r10
  int v10; // r3
  unsigned int v11; // r2
  unsigned int v12; // r0
  int v13; // r0
  unsigned int v14; // r6
  int v15; // r4
  int v16; // r3
  _DWORD *v17; // r2
  unsigned int v18; // r9
  unsigned int v19; // r2
  _DWORD *v20; // lr
  signed int v21; // r4
  _DWORD *v22; // r1
  int v23; // r1
  _DWORD *v24; // r10
  unsigned int v25; // lr
  int v26; // r3
  unsigned int v27; // r8
  int v28; // r0
  signed int v29; // r2
  unsigned int v30; // r1
  int v31; // r8
  _DWORD *i; // r5
  unsigned int v34; // [sp+1Ch] [bp-64h]
  int v35; // [sp+20h] [bp-60h]
  int v36; // [sp+28h] [bp-58h]
  int v37; // [sp+2Ch] [bp-54h]
  char v38; // [sp+30h] [bp-50h]
  int v39; // [sp+34h] [bp-4Ch]
  int v40; // [sp+38h] [bp-48h]
  _DWORD *v41; // [sp+40h] [bp-40h]
  int v42; // [sp+44h] [bp-3Ch]
  int v43; // [sp+48h] [bp-38h]
  int v44; // [sp+58h] [bp-28h]

  v7 = a4;
  v40 = a4;
  v39 = a3;
  v35 = 0;
  v8 = 0;
  v9 = a5;
  while ( v8 < a5 )
  {
    v10 = v7 + 12 * v8;
    v11 = *(_DWORD *)(v10 + 4);
    v12 = *(_DWORD *)(v10 + 8) + v11;
    while ( v11 < v12 )
      v11 += 4096;
    ++v8;
  }
  v13 = ExAllocatePoolWithTag(512, 2560, 2002931011);
  v14 = v13;
  if ( !v13 )
    return 0;
  v16 = 0;
  v17 = (_DWORD *)v13;
  while ( v16 < 64 )
  {
    *v17++ = 0;
    ++v16;
  }
  v42 = 0;
  v36 = 0;
  v43 = 0;
  if ( (a7 & 1) != 0 )
  {
    v43 = CmpSetIoPriorityThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 0);
    v36 = CmpSetPriorityThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 4);
    v42 = 1;
  }
  v38 = CmpSetRespectIoPriorityThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 1);
  v18 = 0;
  v19 = 0;
  v34 = 0;
LABEL_15:
  v20 = a6;
  while ( 1 )
  {
    if ( v18 >= v9 )
    {
      v15 = 1;
      goto LABEL_51;
    }
    v21 = 0;
    v22 = (_DWORD *)(v7 + 12 * v18);
    while ( 1 )
    {
      v41 = v22;
      if ( v18 >= v9 || v21 >= 64 )
        break;
      if ( !v19 )
      {
        *v20 = *v22;
        v35 = v22[1];
        v19 = v22[2];
        v34 = v19;
      }
      v23 = 0;
      v37 = 0;
      v24 = (_DWORD *)(v14 + 4 * v21);
      v25 = v14 + 8 * (v21 + 256);
LABEL_23:
      if ( v19 && v21 < 64 )
      {
        v44 = *a6;
        while ( 1 )
        {
          if ( v23 && (v26 = 0x10000, v19 > 0x10000) || (v26 = 0x100000, v19 > 0x100000) )
            v27 = v26;
          else
            v27 = v19;
          if ( !*v24 )
          {
            v28 = CmpCreateEvent(1, v24, v24 + 64);
            if ( v28 < 0 )
            {
              *(_DWORD *)(v14 + 4 * v21) = 0;
              goto LABEL_48;
            }
            ZwSetInformationObject();
          }
          v28 = ZwWriteFile();
          if ( v28 >= 0 )
          {
            ++v21;
            ++v24;
            v25 += 8;
            *a6 = v44 + v27;
            v19 = v34 - v27;
            v34 -= v27;
            v35 += v27;
            v23 = v37;
            goto LABEL_23;
          }
          if ( v37 )
            goto LABEL_48;
          v23 = 1;
          v37 = 1;
          v19 = v34;
        }
      }
      ++v18;
      v22 = v41 + 3;
      v9 = a5;
      v20 = a6;
    }
    v28 = KeWaitForMultipleObjects(v21, (unsigned int *)(v14 + 256), 0, 0, 0, 0, 0, (int *)(v14 + 512));
    if ( v28 < 0 )
      break;
    v29 = 0;
    v30 = v14;
    while ( v29 < v21 )
    {
      if ( *(int *)(v30 + 2048) < 0 )
        goto LABEL_47;
      ++v29;
      v30 += 8;
    }
    v19 = v34;
    v7 = v40;
    v20 = a6;
    if ( v34 )
    {
      --v18;
      goto LABEL_15;
    }
  }
LABEL_48:
  CmRegistryIODebug = 2;
  dword_92094C = v39;
  dword_920950 = v28;
  if ( v21 > 0 )
    KeWaitForMultipleObjects(v21, (unsigned int *)(v14 + 256), 0, 0, 0, 0, 0, (int *)(v14 + 512));
LABEL_47:
  v15 = 0;
LABEL_51:
  v31 = 0;
  for ( i = (_DWORD *)v14; v31 < 64 && *i; ++i )
  {
    ObfDereferenceObject(i[64]);
    ZwSetInformationObject();
    ZwClose();
    ++v31;
  }
  ExFreePoolWithTag(v14);
  if ( v42 )
  {
    CmpSetIoPriorityThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, v43);
    CmpSetPriorityThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, v36);
  }
  CmpSetRespectIoPriorityThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, v38);
  return v15;
}
