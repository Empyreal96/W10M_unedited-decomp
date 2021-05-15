// MiCreateFreePfns 
 
int __fastcall MiCreateFreePfns(_DWORD *a1)
{
  int *v1; // r2
  unsigned int v3; // r0
  int *v4; // r4
  unsigned int v5; // r8
  char *v6; // r1
  unsigned int v7; // r5
  _DWORD *v8; // r0
  int result; // r0
  int v10; // r1
  int v11; // r2
  int v12; // r3
  unsigned int v13; // r4
  int v14; // r7
  unsigned int v15; // r10
  char *v16; // r3
  _DWORD *v17; // r2
  int v18; // r3
  int v19; // r1
  char *v20; // [sp+4h] [bp-9Ch]
  _DWORD v21[3]; // [sp+10h] [bp-90h] BYREF
  unsigned int v22; // [sp+1Ch] [bp-84h]
  int v23; // [sp+20h] [bp-80h]
  char v24[96]; // [sp+40h] [bp-60h] BYREF

  v1 = MxFreeDescriptor;
  v3 = a1[3];
  v4 = &MxFreeDescriptor[4 * (unsigned __int16)KeNumberNodes];
  v5 = 0;
  if ( MxFreeDescriptor >= v4 )
    goto LABEL_7;
  v6 = v24;
  v7 = a1[4] + v3;
  do
  {
    if ( v1[1] && *v1 < v7 && *v1 >= v3 )
    {
      *(_DWORD *)v6 = v1;
      v6 += 4;
      ++v5;
    }
    v1 += 4;
  }
  while ( v1 < v4 );
  if ( v5 )
  {
    qsort((unsigned int)v24, v5, 4u, (int (__fastcall *)(unsigned int, _BYTE *))MxDescriptorSort);
    v10 = a1[1];
    v11 = a1[2];
    v12 = a1[3];
    v21[0] = *a1;
    v21[1] = v10;
    v21[2] = v11;
    v22 = v12;
    v23 = a1[4];
    v13 = 0;
    v14 = v23;
    v15 = v12;
    v16 = v24;
    do
    {
      v17 = *(_DWORD **)v16;
      v20 = v16 + 4;
      if ( **(_DWORD **)v16 > v15 )
        return sub_96B328();
      v18 = v17[1];
      v19 = a1[2];
      v14 -= v18;
      v15 += v18;
      v22 = v15;
      v23 = v14;
      result = MxReleaseFreeDescriptor((int)v17, v19);
      if ( !v14 )
        return result;
      ++v13;
      v16 = v20;
    }
    while ( v13 < v5 );
    v8 = v21;
  }
  else
  {
LABEL_7:
    v8 = a1;
  }
  return MxCreateFreePfns(v8);
}
