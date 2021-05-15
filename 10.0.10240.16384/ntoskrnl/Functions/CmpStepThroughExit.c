// CmpStepThroughExit 
 
int __fastcall CmpStepThroughExit(int *a1, int *a2, int a3, int a4)
{
  int v5; // r5
  int v7; // r4
  int v8; // r0
  int v10; // r4
  int v11[6]; // [sp+0h] [bp-18h] BYREF

  v11[0] = a3;
  v11[1] = a4;
  v5 = *a1;
  v7 = *a2;
  v11[0] = -1;
  v8 = (*(int (__fastcall **)(int, int, int *))(v5 + 4))(v5, v7, v11);
  if ( !v8 )
    return -1073741670;
  if ( (*(_WORD *)(v8 + 2) & 2) != 0 )
    return sub_7E628C();
  *a2 = v7;
  v10 = 0;
  *a1 = v5;
  (*(void (__fastcall **)(int, int *, int))(v5 + 8))(v5, v11, v5);
  return v10;
}
