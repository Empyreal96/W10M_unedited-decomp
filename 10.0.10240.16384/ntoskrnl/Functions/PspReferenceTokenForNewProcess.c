// PspReferenceTokenForNewProcess 
 
int __fastcall PspReferenceTokenForNewProcess(int a1, int a2, int a3, int *a4)
{
  int v5; // r4
  int result; // r0
  int v7[4]; // [sp+8h] [bp-10h] BYREF

  v7[0] = a3;
  v7[1] = (int)a4;
  if ( !a2 )
  {
    if ( a1 )
    {
      v5 = PsReferencePrimaryToken(a1);
    }
    else
    {
      v5 = PspBootAccessToken;
      ObfReferenceObject(PspBootAccessToken);
    }
    goto LABEL_4;
  }
  result = ObReferenceObjectByHandle(a2, 1, SeTokenObjectType, (char)a3, v7);
  v5 = v7[0];
  if ( result >= 0 )
  {
LABEL_4:
    *a4 = v5;
    result = 0;
  }
  return result;
}
