// KiDetectHeterogeneousSets 
 
int __fastcall KiDetectHeterogeneousSets(int a1)
{
  unsigned int v2; // r5
  unsigned int v4; // r0
  unsigned int v5; // r2
  int *v6; // r4
  unsigned int v7; // r1
  int v8; // t1
  unsigned int v9; // r3
  int v10; // r1
  void **i; // r4
  unsigned __int16 *v12; // t1
  int v13; // [sp-4h] [bp-50h] BYREF
  int v14[2]; // [sp+4h] [bp-48h] BYREF
  char v15[32]; // [sp+Ch] [bp-40h] BYREF

  v2 = KeNumberProcessors_0;
  v14[0] = 0;
  v14[1] = 0;
  memset(v15, 0, sizeof(v15));
  if ( !KeNumberProcessors_0 )
    JUMPOUT(0x69436C);
  v14[0] = 0;
  if ( off_617B54(42, 8, v14, &v13) >= 0 )
    return sub_69435C();
  v4 = *((unsigned __int16 *)KiProcessorBlock + 480);
  v5 = v4;
  if ( v2 > 1 )
  {
    v6 = &dword_681D84;
    v7 = v2 - 1;
    do
    {
      v8 = *v6++;
      v9 = *(unsigned __int16 *)(v8 + 960);
      if ( v9 < v4 )
        v4 = v9;
      if ( v9 > v5 )
        v5 = v9;
      --v7;
    }
    while ( v7 );
    if ( v4 != v5 )
    {
      v10 = 0;
      for ( i = &KiProcessorBlock; ; ++i )
      {
        v12 = (unsigned __int16 *)*i;
        if ( v12[480] == v4 )
          *(_DWORD *)(a1 + 8) |= 1 << v10;
        if ( ++v10 >= v2 )
          JUMPOUT(0x6943BA);
      }
    }
  }
  return 0;
}
