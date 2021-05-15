// sub_80E390 
 
void __fastcall sub_80E390(int a1, int a2, int a3, int a4, int a5, int a6, unsigned int a7, unsigned int a8)
{
  int v8; // r4
  int v9; // r5
  int v10; // r7
  int v11; // r8
  int v12; // r3
  __int16 v13; // r2
  unsigned __int64 v14; // kr00_8
  unsigned __int64 v15; // r0

  v12 = *(_DWORD *)(v8 + 36);
  *(_DWORD *)(v8 + 92) = v11;
  if ( *(_QWORD *)(v12 + 16) )
  {
    (*(void (__fastcall **)(int, int))(v10 + 132))(v10, v8);
    v13 = *(_WORD *)(v8 + 48);
    if ( (v13 & 0x40) == 0 )
    {
      v14 = *(_QWORD *)v8 - 1i64;
      if ( v14 <= *(_QWORD *)v8 && v14 >= *(_QWORD *)*(_DWORD *)(v8 + 36) )
      {
        LODWORD(v15) = KeQueryInterruptTime();
        if ( v15 <= __PAIR64__(a7, a8) )
        {
          *(_QWORD *)(v8 + 24) = v14;
          JUMPOUT(0x7969CE);
        }
      }
      JUMPOUT(0x7969C0);
    }
    *(_WORD *)(v8 + 48) = v13 & 0xFFBF;
  }
  if ( v8 == v9 )
    JUMPOUT(0x796A1C);
  JUMPOUT(0x7969A2);
}
