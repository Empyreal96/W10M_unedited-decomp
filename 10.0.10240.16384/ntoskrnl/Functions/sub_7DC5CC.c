// sub_7DC5CC 
 
void __fastcall sub_7DC5CC(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // r5
  char v9; // r7
  int *v10; // r8
  int *v11; // r6
  int v12; // r1
  unsigned int v13; // r0
  __int16 v14; // lr
  __int16 v15; // r10
  __int16 *v16; // r2
  int v17; // lr
  int v18; // t1
  int v19; // r5
  unsigned int i; // r9
  int v21; // r3

  if ( v10 )
  {
    v11 = v10;
  }
  else
  {
    v11 = &a5;
    a5 = 0;
    a6 = 0;
    a7 = 0;
    a8 = 0;
    SeCaptureSubjectContext(&a5, a2, a3, 0);
  }
  v12 = *v11;
  if ( *v11 || (v12 = v11[2]) != 0 )
  {
    if ( *(_BYTE *)(v12 + 118) == 2 )
    {
      v13 = 0;
      v14 = 0;
      v15 = 0;
      if ( v8 )
      {
        v16 = AdtpPerCategoryCount;
        v17 = v8;
        do
        {
          v18 = (unsigned __int16)*v16++;
          v13 += v18;
          --v17;
        }
        while ( v17 );
        v14 = 0;
      }
      v19 = (unsigned __int16)AdtpPerCategoryCount[v8];
      for ( i = v19 + v13; v13 < i; ++v13 )
      {
        v21 = *(unsigned __int8 *)(v12 + (v13 >> 1) + 88) >> (4 * (v13 & 1));
        if ( (v21 & 1) != 0 )
        {
          if ( (v9 & 2) != 0 )
            break;
          ++v14;
        }
        if ( (v21 & 4) != 0 )
        {
          if ( (v9 & 0x20) != 0 )
            break;
          ++v15;
        }
      }
    }
  }
  else
  {
    SepAuditFailed();
  }
  if ( !v10 )
    SeReleaseSubjectContext((int)v11);
  JUMPOUT(0x6E8CAA);
}
