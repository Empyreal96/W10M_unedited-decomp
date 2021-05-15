// sub_8A10B0 
 
int __fastcall sub_8A10B0(int a1, int a2, int a3, int a4)
{
  int v5; // r3
  int result; // r0
  int *v7; // r5
  _DWORD *v8; // r0
  int v9; // [sp+4h] [bp-14h]

  v9 = a2;
  if ( a2 )
  {
    v5 = ExpFastCacheReArmed;
    __dmb(0xBu);
    if ( v5 )
      return -1073700219;
  }
  v7 = &dword_920288[10 * a1];
  if ( v7[8] || (result = sub_7B5F04((int)&unk_9202A0 + 40 * a1, &dword_9202A8[10 * a1]), result >= 0) )
  {
    v8 = (_DWORD *)v7[8];
    if ( a2 )
    {
      result = CmSetValueKey(v8, (unsigned __int16 *)&dword_8C8224, 3, a2, *(_DWORD *)(a2 + 8) + 24, 0, 0);
    }
    else
    {
      result = CmDeleteValueKey(v8, 786442, 9223008, 0, 0, v9, a3, a4);
      if ( result == -1073741772 )
        result = 0;
    }
  }
  return result;
}
