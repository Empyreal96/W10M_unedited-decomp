// PspCreatePicoThread 
 
int __fastcall PspCreatePicoThread(unsigned __int8 *a1, int a2)
{
  _DWORD *v2; // r5
  unsigned __int8 *v3; // r8
  char v4; // r9
  unsigned int v5; // r7
  int v6; // r6
  unsigned int *v7; // r0
  unsigned int v8; // r4
  unsigned int v9; // r1
  _DWORD *v10; // r4
  _DWORD *v11; // r2
  unsigned int v12; // r4
  unsigned int v13; // r1
  __int16 v14; // r3
  int v16; // [sp+Ch] [bp-33Ch]
  int v17; // [sp+20h] [bp-328h] BYREF
  _DWORD *v18; // [sp+24h] [bp-324h] BYREF
  _DWORD *v19; // [sp+28h] [bp-320h]
  int v20; // [sp+2Ch] [bp-31Ch] BYREF
  int v21[4]; // [sp+30h] [bp-318h] BYREF
  int v22[104]; // [sp+40h] [bp-308h] BYREF
  char v23[360]; // [sp+1E0h] [bp-168h] BYREF

  v2 = 0;
  v17 = 0;
  v18 = 0;
  v19 = (_DWORD *)a2;
  v3 = a1;
  v4 = 0;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( *((_DWORD *)a1 + 19) )
  {
    a1 = (unsigned __int8 *)ObReferenceObjectByHandleWithTag(*(_DWORD *)a1, 2, PsProcessType, 0, 1917023056, &v17, 0);
    v6 = (int)a1;
    if ( (int)a1 >= 0 )
    {
      v2 = (_DWORD *)v17;
      if ( *(_DWORD *)(v17 + 780) )
      {
        --*(_WORD *)(v5 + 308);
        v7 = v2 + 43;
        __pld(v2 + 43);
        v4 = 1;
        v8 = v2[43] & 0xFFFFFFFE;
        do
          v9 = __ldrex(v7);
        while ( v9 == v8 && __strex(v8 + 2, v7) );
        __dmb(0xBu);
        if ( v9 == v8 || (a1 = (unsigned __int8 *)ExfAcquireRundownProtection(v7)) != 0 )
        {
          v4 = 3;
          ObfReferenceObjectWithTag((int)v2);
          memset(v22, 0, sizeof(v22));
          PspCreateUserContext((int)v22, *((_DWORD *)v3 + 2), *(_QWORD *)(v3 + 12));
          v22[14] = *((_DWORD *)v3 + 1);
          v22[15] = *((_DWORD *)v3 + 7);
          v21[1] = *((_DWORD *)v3 + 5);
          v21[2] = *((_DWORD *)v3 + 6);
          v22[3] = *((_DWORD *)v3 + 8);
          v22[4] = *((_DWORD *)v3 + 9);
          v22[5] = *((_DWORD *)v3 + 10);
          v22[6] = *((_DWORD *)v3 + 11);
          v22[7] = *((_DWORD *)v3 + 12);
          v22[8] = *((_DWORD *)v3 + 13);
          v22[9] = *((_DWORD *)v3 + 14);
          v22[10] = *((_DWORD *)v3 + 15);
          v22[11] = *((_DWORD *)v3 + 16);
          v22[12] = *((_DWORD *)v3 + 17);
          v22[13] = *((_DWORD *)v3 + 18);
          v17 = 1;
          v21[0] = 0;
          a1 = (unsigned __int8 *)PspAllocateThread((int)v2, 0, 0, 0, v22, v21, 0, 0, &v17, &v18, 0, (int)v23);
          v6 = (int)a1;
          if ( (int)a1 >= 0 )
          {
            v10 = v18;
            a1 = (unsigned __int8 *)PspInsertThread(v18, v2, 0, &v17, 0x1FFFFF, 0, 0, v16, (int)v23, &v20, 0);
            v6 = (int)a1;
            if ( (int)a1 >= 0 )
            {
              v11 = v19;
              v6 = 0;
              v10[268] = *((_DWORD *)v3 + 19);
              *v11 = v20;
            }
            if ( v10 )
              a1 = (unsigned __int8 *)ObfDereferenceObject((int)v10);
          }
        }
        else
        {
          v6 = -1073741558;
        }
      }
      else
      {
        v6 = -1073741816;
      }
    }
    else
    {
      v2 = 0;
    }
  }
  else
  {
    v6 = -1073741811;
  }
  if ( (v4 & 2) != 0 )
  {
    a1 = (unsigned __int8 *)(v2 + 43);
    __pld(v2 + 43);
    v12 = v2[43] & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v13 = __ldrex((unsigned int *)a1);
    while ( v13 == v12 && __strex(v12 - 2, (unsigned int *)a1) );
    if ( v13 != v12 )
      a1 = ExfReleaseRundownProtection(a1);
  }
  if ( (v4 & 1) != 0 )
  {
    v14 = *(_WORD *)(v5 + 308) + 1;
    *(_WORD *)(v5 + 308) = v14;
    if ( !v14 && *(_DWORD *)(v5 + 100) != v5 + 100 && !*(_WORD *)(v5 + 310) )
      KiCheckForKernelApcDelivery((int)a1);
  }
  if ( v2 )
    ObfDereferenceObjectWithTag((int)v2);
  return v6;
}
