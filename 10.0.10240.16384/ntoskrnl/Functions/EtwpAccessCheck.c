// EtwpAccessCheck 
 
int __fastcall EtwpAccessCheck(int a1, int a2, char *a3)
{
  char *v6; // r1
  int v8; // [sp+18h] [bp-28h] BYREF
  char v9[4]; // [sp+1Ch] [bp-24h] BYREF
  char v10[32]; // [sp+20h] [bp-20h] BYREF

  if ( a3 )
  {
    v6 = a3;
  }
  else
  {
    SeCaptureSubjectContext(v10);
    v6 = v10;
  }
  SeAccessCheck(a1, (int)v6, 0, a2, 0, 0, (int)EtwpGenericMapping, 1, (int)v9, (int)&v8);
  if ( !a3 )
    SeReleaseSubjectContext(v10);
  return v8;
}
