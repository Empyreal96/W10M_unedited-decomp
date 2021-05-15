// -NpStart@NP_CONTEXT@@SAJPAU1@PAU_NP_PARAMETERS@1@@Z 
 
int __fastcall NP_CONTEXT::NpStart(struct NP_CONTEXT *a1, struct NP_CONTEXT::_NP_PARAMETERS *a2, int a3, int a4)
{
  int v5; // r3
  int *v6; // r4
  int *v7; // r5
  int v10; // r0
  int v11; // r1
  int v12; // r2
  int v13; // r3
  _DWORD *v14; // r7
  _DWORD *v15; // r6
  int v16; // r3
  int *v17; // [sp+0h] [bp-18h] BYREF
  int *v18; // [sp+4h] [bp-14h]

  v17 = (int *)a3;
  v18 = (int *)a4;
  v5 = *((_DWORD *)a2 + 1);
  v6 = (int *)&v17;
  v7 = 0;
  v17 = 0;
  v18 = (int *)&v17;
  if ( v5 )
    return sub_510CEC();
  v10 = *(_DWORD *)a2;
  v11 = *((_DWORD *)a2 + 1);
  v12 = *((_DWORD *)a2 + 2);
  v13 = *((_DWORD *)a2 + 3);
  v14 = (_DWORD *)((char *)a2 + 16);
  *(_DWORD *)a1 = v10;
  *((_DWORD *)a1 + 1) = v11;
  *((_DWORD *)a1 + 2) = v12;
  *((_DWORD *)a1 + 3) = v13;
  v15 = (_DWORD *)((char *)a1 + 16);
  v16 = v14[1];
  *v15 = *v14;
  v15[1] = v16;
  while ( v6 != (int *)&v17 )
  {
    v17 = (int *)*v7;
    if ( v7 == v6 )
    {
      v18 = (int *)&v17;
      v17 = 0;
    }
    else
    {
      --*v6;
    }
    ExFreePoolWithTag(v7, 0);
    v7 = v17;
    v6 = v18;
  }
  return 0;
}
