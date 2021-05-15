// sub_54DA9C 
 
void __fastcall sub_54DA9C(int a1, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // r4
  int v6; // r5
  int v7; // r6

  if ( a4 == 1 )
  {
    v7 = *(_DWORD *)(v6 + 52) + 4 * a2;
    if ( FioFwReadUlongAtOffset(*(_DWORD *)(*(_DWORD *)(v6 + 8) + 8), v7, &a5) >= 0 )
    {
      *v5 = a5;
      if ( FioFwReadUlongAtOffset(*(_DWORD *)(*(_DWORD *)(v6 + 8) + 8), v7 + 4, &a5) >= 0 )
        JUMPOUT(0x4E2F96);
    }
  }
  JUMPOUT(0x4E2F9A);
}
