// PfLogDeleteHelper 
 
int __fastcall PfLogDeleteHelper(char a1, int a2, int a3, unsigned int a4)
{
  int v8; // r4
  _DWORD *v9; // r5
  int v10; // r0
  int v11; // r0
  int v13[2]; // [sp+0h] [bp-28h] BYREF
  unsigned int v14; // [sp+8h] [bp-20h] BYREF
  unsigned int v15; // [sp+Ch] [bp-1Ch]

  v13[1] = a2;
  v15 = a4;
  v13[0] = 0;
  v14 = 0;
  v8 = PfFbLogEntryReserve(&qword_6439A0, v13, &v14, 24);
  if ( v8 < 0 )
  {
    v11 = v13[0];
  }
  else
  {
    v9 = (_DWORD *)v14;
    *(_DWORD *)(v14 + 16) = a1 & 3 | (4 * a4);
    v9[5] = a2;
    *v9 = *v9 & 0x80000000 | 0xC3;
    KeQueryTickCount((int *)&v14);
    v10 = v13[0];
    v9[1] = dword_63728C
          + ((__int64)(((v14 * (unsigned __int64)MEMORY[0xFFFF9004]) >> 24)
                     + ((v15 * (unsigned __int64)MEMORY[0xFFFF9004]) << 8)) >> 10);
    v9[2] = a3;
    PfFbLogEntryComplete(v10);
    v11 = 0;
    v8 = 0;
  }
  if ( v11 )
    PfFbLogEntryComplete(v11);
  return v8;
}
