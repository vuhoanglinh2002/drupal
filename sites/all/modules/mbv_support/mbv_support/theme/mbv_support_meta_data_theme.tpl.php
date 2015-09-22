<?php
/**
 * @author baonguyen
 *
 */

print_props($meta);

function print_props($obj){
 if(is_array($obj) || is_object($obj)){
  if(is_object($obj) || isAssoc($obj)){
   print "<ul>";
   foreach($obj as $key=>$value){
    print "<li>" . '<b>' . check_plain($key) . ':</b> ';
    print_props($value);
    print "</li>";
   }
   print "</ul>";
  }else{
   print "<ol>";
   foreach($obj as $value){
    print "<li>";
    print_props($value);
    print "</li>";
   }
   print "</ol>";
  }
 }else{
  print $obj;
 }
}

function isAssoc($arr)
{
 return array_keys($arr) !== range(0, count($arr) - 1);
}