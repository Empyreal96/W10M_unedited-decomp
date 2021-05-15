// ResFwBackgroundTransition 
 
int __fastcall ResFwBackgroundTransition(int result)
{
  if ( result == 1 )
    return ResFwpPageOutBackground(1);
  if ( !result )
    return ResFwpPageInBackground();
  if ( result == 2 && (dword_619018 & 0xC00) != 3072 )
    result = sub_8DF728();
  return result;
}
