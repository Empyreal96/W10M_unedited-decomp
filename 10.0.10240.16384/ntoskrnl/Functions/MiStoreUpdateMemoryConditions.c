// MiStoreUpdateMemoryConditions 
 
_DWORD *__fastcall MiStoreUpdateMemoryConditions(int *a1)
{
  unsigned int v1; // r2
  int v3; // r4
  int v4; // r6
  int v5; // r7
  unsigned int v6; // r1
  _DWORD *result; // r0

  v1 = a1[928];
  if ( v1 >= 0x80 )
  {
    if ( v1 >= 0x400 )
    {
      v6 = a1[1030];
      v4 = 8;
      v5 = 0;
      if ( v6 < v1 + 0x4000 )
      {
        v3 = 4;
      }
      else if ( v6 < v1 + 0x4000 + v1 )
      {
        v3 = 3;
      }
      else
      {
        v3 = 2;
      }
    }
    else
    {
      v3 = 1;
      v4 = 18;
      v5 = 0;
    }
  }
  else
  {
    v3 = 0;
    v4 = 18;
    v5 = 1;
  }
  if ( KeQueryEffectiveBasePriorityThread(a1[173]) != v4 )
    KeSetActualBasePriorityThread(a1[173], v4);
  if ( v5 )
    KeSetEvent((int)(a1 + 174), 0, 0);
  result = SmGlobals;
  if ( dword_636CB4 != v3 || v3 <= 0 )
  {
    dword_636CB4 = v3;
    __dmb(0xFu);
    result = (_DWORD *)SMKM_STORE_MGR<SM_TRAITS>::SmUpdateMemoryConditions();
  }
  return result;
}
