// PsCreateSystemThreadEx 
 
int __fastcall PsCreateSystemThreadEx(int a1, int a2, int *a3, int a4, int a5, int a6, int a7, int *a8, int *a9)
{
  int v11; // lr
  int v12; // r10
  int v13; // r9
  int v14; // r8
  int v15; // r0
  unsigned int v16; // r1
  signed int v17; // r1
  int v18; // r3
  int *v19; // r3
  int v21; // r0
  int v22; // r1
  int v23; // r2
  int v24; // r3
  int *v25; // r5
  int v26; // r3
  int v27; // r2
  int v28; // r3
  int v29; // [sp+28h] [bp-138h]
  int v30; // [sp+2Ch] [bp-134h]
  int v31; // [sp+38h] [bp-128h] BYREF
  int v32; // [sp+3Ch] [bp-124h]
  int v33; // [sp+40h] [bp-120h]
  int v34; // [sp+44h] [bp-11Ch]
  int v35; // [sp+48h] [bp-118h]
  int v36; // [sp+4Ch] [bp-114h]
  int v37[68]; // [sp+50h] [bp-110h] BYREF

  v29 = a2;
  v30 = a1;
  v11 = a2;
  v12 = a1;
  if ( a4 )
  {
    v14 = a4;
    v13 = 0;
  }
  else
  {
    v13 = PsInitialSystemProcess;
    v14 = 0;
    memset(v37, 0, 240);
    v37[1] = 4096;
    if ( a8 )
    {
      v27 = a8[1];
      v28 = a8[2];
      v37[48] = *a8;
      v37[49] = v27;
      v37[50] = v28;
    }
    else
    {
      v15 = KeQueryActiveGroupCount();
      __dmb(0xBu);
      do
      {
        v16 = __ldrex(&PspSystemThreadAssignment);
        v17 = v16 + 1;
      }
      while ( __strex(v17, &PspSystemThreadAssignment) );
      __dmb(0xBu);
      if ( !v15 )
        __brkdiv0();
      LOWORD(v37[49]) = v17 % v15;
      v18 = dword_681D78[LOWORD(v37[49])];
      __dmb(0xBu);
      v37[48] = v18;
    }
    v11 = v29;
    v12 = v30;
    if ( a9 )
    {
      v37[1] |= 0x4000u;
      v37[37] = *a9;
    }
  }
  if ( a3 )
  {
    v21 = *a3;
    v22 = a3[1];
    v23 = a3[2];
    v24 = a3[3];
    v25 = a3 + 4;
    v31 = v21;
    v32 = v22;
    v33 = v23;
    v34 = v24;
    v26 = v25[1];
    v35 = *v25;
    v36 = v26;
    v34 |= 0x200u;
  }
  else
  {
    v31 = 24;
    v32 = 0;
    v34 = 512;
    v33 = 0;
    v35 = 0;
    v36 = 0;
  }
  if ( a4 )
    v19 = 0;
  else
    v19 = v37;
  return PspCreateThread(v12, v11, &v31, v14, v13, v19, a5, 0, 0, 0, a6, a7, 0);
}
