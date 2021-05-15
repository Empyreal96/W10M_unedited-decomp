// sub_55367C 
 
void __fastcall sub_55367C(int a1, int a2, int a3, int a4, int a5, int a6, _DWORD *a7, __int64 a8, __int64 a9)
{
  int v9; // r10
  __int64 v10; // kr00_8
  __int64 v11; // r6
  __int64 v12; // r8
  __int64 v13; // kr08_8

  (*(void (__fastcall **)(int, int, __int64 *, __int64 *))v9)(a1, a2, &a8, &a9);
  v10 = *(_QWORD *)(v9 + 16);
  if ( a8 != v10 )
  {
    v12 = *(_QWORD *)(v9 + 8);
    v11 = a8 - v10;
    v13 = a9 - v12;
    if ( a8 == v10 )
      __brkdiv0();
    *(_DWORD *)(v9 + 24) = _rt_udiv64(a8 - v10, (a9 - v12) * *(unsigned __int8 *)(v9 + 34));
    *(_QWORD *)(v9 + 16) = v10 + v11;
    *(_QWORD *)(v9 + 8) = v12 + v13;
  }
  *a7 = *(_DWORD *)(v9 + 24);
  JUMPOUT(0x4F3C52);
}
