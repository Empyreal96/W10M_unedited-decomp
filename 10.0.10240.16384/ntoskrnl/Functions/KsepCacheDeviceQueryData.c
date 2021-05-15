// KsepCacheDeviceQueryData 
 
unsigned __int16 *__fastcall KsepCacheDeviceQueryData(int a1, unsigned __int16 *a2, int a3, int a4)
{
  unsigned __int16 *v5; // r5
  unsigned __int16 *v6; // r6
  unsigned __int16 *v7; // r4
  unsigned __int16 v9; // [sp+0h] [bp-18h] BYREF
  int v10; // [sp+4h] [bp-14h]
  int v11; // [sp+8h] [bp-10h]

  v10 = a3;
  v11 = a4;
  v5 = *(unsigned __int16 **)(a1 + 28);
  RtlInitUnicodeString((unsigned int)&v9, a2);
  v6 = (unsigned __int16 *)(a1 + 28);
  while ( v5 != v6 )
  {
    v7 = v5;
    v5 = *(unsigned __int16 **)v5;
    if ( RtlEqualUnicodeString(v7 + 4, &v9, 1) )
      return v7;
  }
  return 0;
}
