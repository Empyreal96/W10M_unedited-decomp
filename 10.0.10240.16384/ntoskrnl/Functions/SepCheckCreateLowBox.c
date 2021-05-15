// SepCheckCreateLowBox 
 
int __fastcall SepCheckCreateLowBox(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r0
  int v6; // r2
  int v8; // [sp+0h] [bp-20h] BYREF
  int v9; // [sp+4h] [bp-1Ch]
  int v10; // [sp+8h] [bp-18h]
  int v11; // [sp+Ch] [bp-14h]

  v8 = a1;
  v9 = a2;
  v10 = a3;
  v11 = a4;
  v4 = 0;
  v5 = SeCaptureSubjectContext(&v8);
  v6 = v8;
  if ( !v8 )
  {
    v6 = v10;
LABEL_3:
    v4 = *(_DWORD *)(v6 + 176) & 0x2000;
    goto LABEL_4;
  }
  if ( v9 >= 2 )
    goto LABEL_3;
LABEL_4:
  if ( !v4 )
    return sub_7EA704(v5);
  SeReleaseSubjectContext((int)&v8);
  return 0;
}
