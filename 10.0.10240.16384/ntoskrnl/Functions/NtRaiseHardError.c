// NtRaiseHardError 
 
int __fastcall NtRaiseHardError(int a1, unsigned int a2, int a3, unsigned int a4, unsigned int a5, _DWORD *a6)
{
  int result; // r0
  _DWORD *v9; // r2
  int v10; // r10
  unsigned int v11; // r3
  unsigned int v12; // r2
  _DWORD *v13; // r1
  _DWORD *v14; // r5
  unsigned int v15; // r3
  unsigned int v16; // r1
  _DWORD *v17; // r4
  int v19; // [sp+14h] [bp-8Ch] BYREF
  _DWORD *v20; // [sp+18h] [bp-88h]
  _DWORD *v21; // [sp+1Ch] [bp-84h]
  unsigned int v22; // [sp+20h] [bp-80h]
  _DWORD v23[6]; // [sp+28h] [bp-78h] BYREF
  _DWORD _40[30]; // [sp+40h] [bp-60h] BYREF

  _40[29] = a4;
  _40[28] = a3;
  _40[27] = a2;
  v19 = a1;
  _40[26] = a1;
  v20 = a6;
  v21 = a6;
  if ( a2 > 5 || a4 && !a2 )
    return -1073741584;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
  {
    if ( a5 > 8 )
    {
      result = -1073741582;
    }
    else
    {
      v9 = a6;
      if ( (unsigned int)a6 >= MmUserProbeAddress )
        v9 = (_DWORD *)MmUserProbeAddress;
      *v9 = *v9;
      if ( a4 )
      {
        v10 = 4 * a2;
        if ( 4 * a2 )
        {
          if ( (a4 & 3) != 0 )
            ExRaiseDatatypeMisalignment();
          v11 = v10 + a4;
          if ( v10 + a4 > MmUserProbeAddress || v11 < a4 )
            *(_BYTE *)MmUserProbeAddress = 0;
        }
        memmove((int)v23, a4, 4 * a2);
        memmove((int)_40, (int)v23, 4 * a2);
        if ( a3 )
        {
          v12 = 0;
          v22 = 0;
          while ( v12 < a2 )
          {
            if ( ((1 << v12) & a3) != 0 )
            {
              v13 = (_DWORD *)v23[v12];
              if ( ((unsigned __int8)v13 & 3) != 0 )
                ExRaiseDatatypeMisalignment();
              v14 = &_40[2 * v12 + 6];
              *v14 = *v13;
              v14[1] = v13[1];
              if ( *((_WORD *)v14 + 1) )
              {
                v15 = v14[1];
                v16 = *((unsigned __int16 *)v14 + 1) + v15;
                if ( v16 > MmUserProbeAddress || v16 < v15 )
                  *(_BYTE *)MmUserProbeAddress = 0;
              }
              _40[v12] = v14;
            }
            v22 = ++v12;
          }
        }
      }
      v17 = v20;
      result = ExpRaiseHardError(v19, a2, a3, (int)v23, (int)_40, a5, (unsigned int *)&v19);
      v21 = (_DWORD *)result;
      *v17 = v19;
    }
  }
  else
  {
    result = ExRaiseHardError(a1, a2, a3, (_DWORD **)a4, a5, &v19);
    *a6 = v19;
  }
  return result;
}
