// CcPinMappedData 
 
int __fastcall CcPinMappedData(int a1, __int64 *a2, int a3, int a4, int *a5)
{
  int v5; // r6
  int *v8; // lr
  int v9; // r8
  unsigned int *v10; // r0
  unsigned int v11; // r1
  int v12; // r0
  unsigned int v13; // r5
  unsigned int v14; // r1
  char v16; // [sp+18h] [bp-48h]
  int v17; // [sp+1Ch] [bp-44h] BYREF
  int *v18; // [sp+20h] [bp-40h]
  int v19; // [sp+24h] [bp-3Ch]
  int *v20; // [sp+28h] [bp-38h]
  int v21; // [sp+2Ch] [bp-34h] BYREF
  unsigned __int64 v22; // [sp+30h] [bp-30h] BYREF
  __int64 v23; // [sp+38h] [bp-28h] BYREF
  int varg_r0; // [sp+68h] [bp+8h]
  __int64 *varg_r1; // [sp+6Ch] [bp+Ch]
  int varg_r2; // [sp+70h] [bp+10h]
  int varg_r3; // [sp+74h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v19 = a4;
  v5 = a3;
  v22 = *a2;
  v17 = 0;
  v8 = &v17;
  v18 = &v17;
  if ( (*a5 & 1) != 0 )
  {
    --*a5;
    v9 = *(_DWORD *)(*(_DWORD *)(a1 + 20) + 4);
    v10 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4244);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 + 1, v10) );
    if ( *(_WORD *)*a5 == 765 )
    {
      if ( ExAcquireSharedStarveExclusive(*a5 + 56, (v19 & 1) != 0) )
LABEL_18:
        v16 = 1;
      else
        v16 = 0;
    }
    else
    {
      v12 = v22;
      v13 = HIDWORD(v23);
      v14 = v23;
      while ( 1 )
      {
        if ( v17 )
        {
          if ( v8 == &v17 )
          {
            v17 = CcAllocateObcb(a2, v5);
            v8 = (int *)(v17 + 16);
            v20 = (int *)(v17 + 16);
            v12 = v22;
            v13 = HIDWORD(v23);
            v14 = v23;
          }
          v5 += v12 - v14;
          varg_r2 = v5;
          v22 = __PAIR64__(v13, v14);
          v18 = ++v8;
          v20 = v8;
        }
        if ( !CcPinFileData(a1, &v22, v5, (*(_DWORD *)(v9 + 96) & 0x200) == 0, 0, v19, (int **)v8, &v21, &v23) )
          break;
        v14 = v23;
        v12 = v22;
        v13 = HIDWORD(v23);
        if ( (__int64)(v23 - v22) >= (unsigned int)v5 )
        {
          CcFreeVirtualAddress(*a5);
          *a5 = v17;
          goto LABEL_18;
        }
        v8 = v18;
      }
      v16 = 0;
    }
    if ( !v16 )
    {
      ++*a5;
      if ( v17 )
        CcUnpinData(v17);
    }
    LOBYTE(v19) = v16;
  }
  else
  {
    LOBYTE(v19) = 1;
  }
  return (unsigned __int8)v19;
}
